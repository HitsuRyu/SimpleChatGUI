#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent, QSqlDatabase database, QString login);
    ~ChatWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChatWindow *ui;
    QSqlDatabase    m_db;
    QString         m_login;

};

#endif // CHATWINDOW_H
