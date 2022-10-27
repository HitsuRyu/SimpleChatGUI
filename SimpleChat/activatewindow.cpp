#include "activatewindow.h"
#include "ui_activatewindow.h"

ActivateWindow::ActivateWindow(QWidget *parent, QSqlDatabase &database, bool &flag) :
    QWidget(parent),
    ui(new Ui::ActivateWindow)
{
    QFile     file("/etc/machine-id");

    ui->setupUi(this);
    file.open(QIODevice::ReadOnly);
    m_uuid = file.readLine(32);
    file.close();

    m_db = database;
    m_flag = flag;

    if(m_flag)
        ui->checkPK_label->setText("Активация не требуется!");
}

ActivateWindow::~ActivateWindow()
{
    delete ui;
}

/* ______________________________________ _____ ______________________________________ */

/*                                        SLOTS                                        */

/* ______________________________________ _____ ______________________________________ */

void ActivateWindow::on_checkPK_pushButton_clicked()
{
    if (checkUUID())
        return;

    m_prodkey = ui->prodkey_lineEdit->text();

    if (!checkProductKeyValidity())
    {
        m_prodkey.clear();
        ui->prodkey_lineEdit->clear();
        ui->checkPK_label->setText("Недействительный ключ продукта!");
    }
    else
    {
        if (checkProductKeyUsed())
        {
            m_prodkey.clear();
            ui->prodkey_lineEdit->clear();
            ui->checkPK_label->setText("Недействительный ключ продукта!");
        }
        else
        {
            activateProduct();
            emit activated();
            this->close();
        }
    }
}

/* ______________________________________ _____ ______________________________________ */

/*                                        METHODS                                      */

/* ______________________________________ _____ ______________________________________ */

bool ActivateWindow::checkUUID()
{
    QSqlQuery q;
    int       res = 0;

    q.prepare("SELECT COUNT(UUID) FROM UUID_Table WHERE UUID= :uuid");
    q.bindValue(":uuid", m_uuid);
    q.exec();
    while (q.next())
       res = q.value(0).toInt();
    if (res != 0)
        return true;
    return false;
}

bool ActivateWindow::checkProductKeyValidity()
{
    QSqlQuery q;
    int res = 0;

    q.prepare("SELECT COUNT(ProdKey) FROM Product_Key WHERE ProdKey= :pk");
    q.bindValue(":pk", m_prodkey);
    q.exec();

    while (q.next())
       res = q.value(0).toInt();
    if (res != 1)
        return false;
    return true;
}

bool ActivateWindow::checkProductKeyUsed()
{
    QSqlQuery q;
    int res = 0;

    q.prepare("SELECT COUNT(ProdKey) FROM UUID_Table WHERE ProdKey= :pk");
    q.bindValue(":pk", m_prodkey);
    q.exec();

    while (q.next())
       res = q.value(0).toInt();
    if (res != 0)
        return true;
    return false;
}

void ActivateWindow::activateProduct()
{
     QSqlQuery q2;

     q2.prepare("INSERT INTO UUID_Table (ProdKey, UUID) VALUES (:pk,:uuid)");
     q2.bindValue(":pk", m_prodkey);
     q2.bindValue(":uuid", m_uuid);
     q2.exec();

     ui->checkPK_label->setText("Активация не требуется!");
     m_flag = true;
     return;
}
