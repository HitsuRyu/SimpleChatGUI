/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *login_label;
    QLineEdit *login_line;
    QLineEdit *passwd_line;
    QLabel *passwd_label;
    QPushButton *enter_pushButton;
    QPushButton *register_pushButton;
    QPushButton *activate_pushButton;
    QLabel *status_label;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(278, 215);
        mainwindow->setMinimumSize(QSize(278, 215));
        mainwindow->setMaximumSize(QSize(278, 215));
        verticalLayout = new QVBoxLayout(mainwindow);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(mainwindow);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        login_label = new QLabel(groupBox);
        login_label->setObjectName("login_label");

        formLayout->setWidget(0, QFormLayout::LabelRole, login_label);

        login_line = new QLineEdit(groupBox);
        login_line->setObjectName("login_line");
        login_line->setMaxLength(4);
        login_line->setFrame(true);
        login_line->setEchoMode(QLineEdit::Normal);
        login_line->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, login_line);

        passwd_line = new QLineEdit(groupBox);
        passwd_line->setObjectName("passwd_line");
        passwd_line->setMaxLength(6);
        passwd_line->setEchoMode(QLineEdit::Password);
        passwd_line->setClearButtonEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwd_line);

        passwd_label = new QLabel(groupBox);
        passwd_label->setObjectName("passwd_label");

        formLayout->setWidget(1, QFormLayout::LabelRole, passwd_label);

        enter_pushButton = new QPushButton(groupBox);
        enter_pushButton->setObjectName("enter_pushButton");

        formLayout->setWidget(2, QFormLayout::LabelRole, enter_pushButton);

        register_pushButton = new QPushButton(groupBox);
        register_pushButton->setObjectName("register_pushButton");

        formLayout->setWidget(2, QFormLayout::FieldRole, register_pushButton);

        activate_pushButton = new QPushButton(groupBox);
        activate_pushButton->setObjectName("activate_pushButton");

        formLayout->setWidget(3, QFormLayout::SpanningRole, activate_pushButton);

        status_label = new QLabel(groupBox);
        status_label->setObjectName("status_label");

        formLayout->setWidget(4, QFormLayout::SpanningRole, status_label);


        verticalLayout->addWidget(groupBox);


        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "SimpleChat", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mainwindow", "\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203:", nullptr));
        login_label->setText(QCoreApplication::translate("mainwindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        login_line->setText(QString());
        login_line->setPlaceholderText(QString());
        passwd_label->setText(QCoreApplication::translate("mainwindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        enter_pushButton->setText(QCoreApplication::translate("mainwindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        register_pushButton->setText(QCoreApplication::translate("mainwindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        activate_pushButton->setText(QCoreApplication::translate("mainwindow", "\320\220\320\272\321\202\320\270\320\262\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
        status_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
