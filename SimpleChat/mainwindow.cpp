#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    QFile     file("/etc/machine-id");
    file.open(QIODevice::ReadOnly);
    m_uuid = file.readLine(32);
    file.close();

    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("95.165.30.93");
    m_db.setDatabaseName("SimpleChat_db");
    m_db.setUserName("GUI");
    m_db.setPassword("gui_password");
    if (!m_db.open())
        qDebug() << "Cannot open Database!" ;

    m_flag = checkLicense();
    m_attempts = 0;
    m_blocked = false;

    activateWindow = new ActivateWindow(nullptr, m_db, m_flag);
    regWindow = new RegWindow(nullptr, m_db);

    connect(activateWindow, SIGNAL(activated()), this, SLOT(on_activated()));
}

mainwindow::~mainwindow()
{
    delete ui;
    delete chatWindow;
}

/* ______________________________________ _____ ______________________________________ */

/*                                        SLOTS                                        */

/* ______________________________________ _____ ______________________________________ */

void mainwindow::on_activate_pushButton_clicked()
{
    activateWindow->show();
}

void mainwindow::on_register_pushButton_clicked()
{
    if (!m_flag)
    {
        ui->status_label->setText("Требуется активация программы!");
        return;
    }
    regWindow->show();
}

void mainwindow::on_activated()
{
    m_flag = true;
    ui->status_label->setText("Программа активирована!");
}

void mainwindow::on_timerAlarm()
{
    m_attempts = 0;
    m_blocked = false;
}

void mainwindow::on_enter_pushButton_clicked()
{
    if (m_blocked == true)
    {
        ui->status_label->setText("Блокировка на 5 секунд!");
        return;
    }
    m_login = ui->login_line->text();
    m_password = getSHA1(ui->passwd_line->text());
    if (!m_flag)
    {
        ui->status_label->setText("Требуется активация программы!");
        return;
    }

    if (!checkLoginPwd())
    {
        m_attempts++;
        ui->status_label->setText("Логин/Пароль неверны! Попыток: " + QString(QString::number(m_attempts)));
        if (m_attempts == 5)
        {
            m_blocked = true;
            m_timer = new QTimer();
             connect(m_timer, SIGNAL(timeout()), this, SLOT(on_timerAlarm()));
            m_timer->start(5000);
        }
    }

    else
    {
        chatWindow = new ChatWindow(nullptr, m_db, m_login);
        chatWindow->show();
        this->close();
    }
}

/* ______________________________________ _____ ______________________________________ */

/*                                        METHODS                                      */

/* ______________________________________ _____ ______________________________________ */

QString mainwindow::getSHA1(QString str)
{
    unsigned char	buf[20];
    char			out_buf[40];
    std::string     passwd = str.toStdString();

    SHA1((const unsigned char *)passwd.c_str(), passwd.size(), buf);
    memset(out_buf, 0, 40);
    int j = 0;
    for (int i = 0; i < 20; i++)
    {
        sprintf(&out_buf[j], "%02x", buf[i]);
        j+=2;
    }
    passwd.replace(0, 40, out_buf);
    return (QString::fromStdString(passwd));
}

bool mainwindow::checkLicense()
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

bool mainwindow::checkLoginPwd()
{
    QSqlQuery q;
    int       res = 0;

    q.prepare("SELECT COUNT(Login) FROM Login_Pwd WHERE Login= :log AND Password= :pas");
    q.bindValue(":log", m_login);
    q.bindValue(":pas", m_password);
    q.exec();

    while (q.next())
       res = q.value(0).toInt();
    if (res == 0)
        return false;
    else
       return true;
}
