#ifndef ACTIVATEWINDOW_H
#define ACTIVATEWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QFile>

namespace Ui {
class ActivateWindow;
}

class ActivateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ActivateWindow(QWidget *parent, QSqlDatabase &database, bool &flag);
    ~ActivateWindow();

private slots:
    void on_checkPK_pushButton_clicked();

private:
    Ui::ActivateWindow *ui;
    QSqlDatabase       m_db;
    QString            m_uuid;
    bool               m_flag;
    QString            m_prodkey;

    bool               checkUUID();
    bool               checkProductKeyValidity();
    bool               checkProductKeyUsed();
    void               activateProduct();
signals:
    void               activated();
};

#endif // ACTIVATEWINDOW_H
