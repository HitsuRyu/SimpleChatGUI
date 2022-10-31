#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <activatewindow.h>
#include <regwindow.h>
#include <chatwindow.h>
#include <openssl/sha.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private slots:
    void on_activate_pushButton_clicked();

    void on_enter_pushButton_clicked();

    void on_register_pushButton_clicked();

private:
    Ui::mainwindow *ui;
    QSqlDatabase   m_db;
    ActivateWindow *activateWindow;
    RegWindow      *regWindow;
    ChatWindow     *chatWindow;

    QString         m_login;
    QString         m_password;
    QString         m_uuid;
    bool            m_flag;
    int             m_attempts;
    bool            m_blocked;
    QTimer          *m_timer;

    QString         getSHA1(QString str);
    bool            checkLoginPwd();
    bool            checkLicense();

public slots:
    void            on_activated();
    void            on_timerAlarm();
};
#endif // MAINWINDOW_H
