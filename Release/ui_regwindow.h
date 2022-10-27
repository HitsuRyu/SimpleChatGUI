/********************************************************************************
** Form generated from reading UI file 'regwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWINDOW_H
#define UI_REGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *name_line;
    QLineEdit *lastName_line;
    QLineEdit *phone_line;
    QLineEdit *email_line;
    QLineEdit *address_line;
    QLineEdit *login_line;
    QLineEdit *passwd_line;
    QPushButton *reg_pushButton;
    QLabel *status_bar;

    void setupUi(QWidget *RegWindow)
    {
        if (RegWindow->objectName().isEmpty())
            RegWindow->setObjectName("RegWindow");
        RegWindow->resize(450, 345);
        RegWindow->setMinimumSize(QSize(450, 345));
        RegWindow->setMaximumSize(QSize(450, 345));
        horizontalLayout = new QHBoxLayout(RegWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(RegWindow);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        name_line = new QLineEdit(groupBox);
        name_line->setObjectName("name_line");
        name_line->setMaxLength(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, name_line);

        lastName_line = new QLineEdit(groupBox);
        lastName_line->setObjectName("lastName_line");
        lastName_line->setMaxLength(20);

        formLayout->setWidget(1, QFormLayout::FieldRole, lastName_line);

        phone_line = new QLineEdit(groupBox);
        phone_line->setObjectName("phone_line");
        phone_line->setMaxLength(11);

        formLayout->setWidget(2, QFormLayout::FieldRole, phone_line);

        email_line = new QLineEdit(groupBox);
        email_line->setObjectName("email_line");
        email_line->setMaxLength(20);

        formLayout->setWidget(3, QFormLayout::FieldRole, email_line);

        address_line = new QLineEdit(groupBox);
        address_line->setObjectName("address_line");
        address_line->setMaxLength(50);

        formLayout->setWidget(4, QFormLayout::FieldRole, address_line);

        login_line = new QLineEdit(groupBox);
        login_line->setObjectName("login_line");
        login_line->setInputMethodHints(Qt::ImhDigitsOnly);
        login_line->setMaxLength(4);
        login_line->setClearButtonEnabled(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, login_line);

        passwd_line = new QLineEdit(groupBox);
        passwd_line->setObjectName("passwd_line");
        passwd_line->setMaxLength(6);
        passwd_line->setEchoMode(QLineEdit::Password);
        passwd_line->setClearButtonEnabled(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, passwd_line);

        reg_pushButton = new QPushButton(groupBox);
        reg_pushButton->setObjectName("reg_pushButton");

        formLayout->setWidget(7, QFormLayout::FieldRole, reg_pushButton);

        status_bar = new QLabel(groupBox);
        status_bar->setObjectName("status_bar");

        formLayout->setWidget(8, QFormLayout::FieldRole, status_bar);


        horizontalLayout_2->addLayout(formLayout);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(RegWindow);

        QMetaObject::connectSlotsByName(RegWindow);
    } // setupUi

    void retranslateUi(QWidget *RegWindow)
    {
        RegWindow->setWindowTitle(QCoreApplication::translate("RegWindow", "Registration", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RegWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        label->setText(QCoreApplication::translate("RegWindow", "\320\230\320\274\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("RegWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        label_3->setText(QCoreApplication::translate("RegWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275:", nullptr));
        label_4->setText(QCoreApplication::translate("RegWindow", "eMail:", nullptr));
        label_5->setText(QCoreApplication::translate("RegWindow", "\320\220\320\264\321\200\320\265\321\201:", nullptr));
        label_6->setText(QCoreApplication::translate("RegWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_7->setText(QCoreApplication::translate("RegWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        reg_pushButton->setText(QCoreApplication::translate("RegWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        status_bar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegWindow: public Ui_RegWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOW_H
