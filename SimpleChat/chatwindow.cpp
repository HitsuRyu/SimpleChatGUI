#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent, QSqlDatabase database, QString login) :
    QWidget(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);

    m_login = login;
    m_db = database;
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::on_pushButton_clicked()
{
    QSqlQuery   q;
    std::vector<QString>    arr_messages;
    QString                 message;
    std::vector<QString>::iterator it;

    q.prepare("SELECT Permission FROM Login_Pwd WHERE Login = ?");
    q.addBindValue(m_login);
    q.exec();
    while (q.next())
    {
        if (q.value(0).toString() != "r" &&
                q.value(0).toString() != "rw")
        {
            q.clear();
            return;
        }
    }

    q.clear();
    ui->textBrowser->clear();
    q.exec("SELECT Timestamp, Login, MessageData FROM Message");

    while (q.next())
    {
        message.clear();
        message.append("|   ");
        message.append(q.value(0).toString());
        message.append("   |   ");
        message.append(q.value(1).toString());
        message.append("   |   ");
        message.append(q.value(2).toString());
        arr_messages.push_back(message);
    }
    it = arr_messages.begin();
    while (it != arr_messages.end())
    {
        ui->textBrowser->append(*it);
        it++;
    }
}


void ChatWindow::on_pushButton_2_clicked()
{
    if (ui->textEdit->toPlainText() == "")
        return;

    QSqlQuery q;
    q.prepare("SELECT Permission FROM Login_Pwd WHERE Login = ?");
    q.addBindValue(m_login);
    q.exec();
    while (q.next())
    {
        if (q.value(0).toString() != "w" &&
                q.value(0).toString() != "rw")
        {
            q.clear();
            return;
        }
    }

    q.clear();
    std::string timestamp;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char c_timestamp[20];
    memset(c_timestamp, 0, 20);
    sprintf(c_timestamp, "%d.%d.%d %d:%d:%d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    timestamp.replace(0, 20, c_timestamp);

    q.prepare("Insert into Message(Login, Timestamp, MessageData)"
              " VALUES(?, ?, ?);");
    q.addBindValue(m_login);
    q.addBindValue(QString::fromStdString(timestamp));
    q.addBindValue(ui->textEdit->toPlainText());
    q.exec();
    ui->textEdit->clear();
}

