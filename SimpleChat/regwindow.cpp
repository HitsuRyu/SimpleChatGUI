#include "regwindow.h"
#include "ui_regwindow.h"

RegWindow::RegWindow(QWidget *parent, QSqlDatabase &database) :
    QWidget(parent),
    ui(new Ui::RegWindow)
{
    ui->setupUi(this);
    m_db = database;
}

RegWindow::~RegWindow()
{
    delete ui;
}

bool RegWindow::checkDigits(QString input)
{
    std::string str = input.toStdString();
    for (unsigned long i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool RegWindow::checkAlnum(QString input)
{
    std::string str = input.toStdString();
    for (unsigned long i = 0; i < str.size(); i++)
    {
        if (!std::isalnum(str[i]))
            return (false);
    }
    return (true);
}

void RegWindow::fillData()
{
    m_fname = ui->name_line->text();
    m_lname = ui->lastName_line->text();
    m_phone = ui->phone_line->text();
    m_email = ui->email_line->text();
    m_address = ui->address_line->text();
    m_login = ui->login_line->text();
    m_password = ui->passwd_line->text();
}

bool RegWindow::checkData()
{
    if (!checkDigits(m_phone) || m_phone.size() != 11)
    {
        ui->status_bar->setText("Телефон должен быть из 11 цифр!");
        return false;
    }
    else if (!checkDigits(m_login) || m_login.size() != 4)
    {
        ui->status_bar->setText("Логин должен быть из 4 цифр!");
        return false;
    }
    else if (!checkAlnum(m_password) || m_password.size() != 6)
    {
        ui->status_bar->setText("Пароль должен быть из 6 символов a-z | 0-9!");
        return false;
    }
    ui->status_bar->clear();
    return true;
}

bool RegWindow::checkLoginExists()
{
    QSqlQuery q;
    int       res = 0;

    q.prepare("SELECT COUNT(Login) FROM Login_Pwd WHERE Login= :log");
    q.bindValue(":log", m_login);
    q.exec();

    while (q.next())
       res = q.value(0).toInt();
    if (res != 0)
        return true;
    return false;
}

QString RegWindow::getSHA1(QString str)
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


void RegWindow::registerUser()
{
    QSqlQuery q;
    QSqlQuery q1;

    q.prepare("INSERT INTO Login_Pwd (Login, Password) VALUES (:log, :pass)");
    q.bindValue(":log", m_login);
    q.bindValue(":pass", m_password);
    q.exec();

    q1.prepare("INSERT INTO User_Data (Login, Name, LastName, Phone, Email, Address) VALUES(:log, :fnam, :lnam, :ph, :em, :addr)");
    q1.bindValue(":log", m_login);
    q1.bindValue(":fnam", m_fname);
    q1.bindValue(":lnam", m_lname);
    q1.bindValue(":ph", m_phone);
    q1.bindValue(":em", m_email);
    q1.bindValue(":addr", m_address);
    q1.exec();
}

void RegWindow::on_reg_pushButton_clicked()
{
    fillData();

    if (!checkData())
        return;

    if (checkLoginExists())
    {
        ui->status_bar->setText("Пользователь уже существует!");
        return;
    }
    m_password = getSHA1(m_password);
    registerUser();
    ui->status_bar->setText("Пользователь успешно зарегистрирован!");
}

