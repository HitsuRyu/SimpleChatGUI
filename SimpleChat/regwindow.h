#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QWidget>
#include <QtSql>
#include <openssl/sha.h>

namespace Ui {
class RegWindow;
}

class RegWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegWindow(QWidget *parent, QSqlDatabase &database);
    ~RegWindow();

private slots:
    void on_reg_pushButton_clicked();

private:
    Ui::RegWindow *ui;

    QSqlDatabase    m_db;

    QString         m_fname;
    QString         m_lname;
    QString         m_phone;
    QString         m_email;
    QString         m_address;
    QString         m_login;
    QString         m_password;


    bool            checkDigits(QString input);
    bool            checkAlnum(QString input);

    void            fillData();
    bool            checkData();

    bool            checkLoginExists();

    void            registerUser();
    QString         getSHA1(QString str);
};

#endif // REGWINDOW_H
