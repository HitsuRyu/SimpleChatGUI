/********************************************************************************
** Form generated from reading UI file 'activatewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVATEWINDOW_H
#define UI_ACTIVATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActivateWindow
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *prodkey_lineEdit;
    QPushButton *checkPK_pushButton;
    QLabel *checkPK_label;

    void setupUi(QWidget *ActivateWindow)
    {
        if (ActivateWindow->objectName().isEmpty())
            ActivateWindow->setObjectName("ActivateWindow");
        ActivateWindow->resize(553, 151);
        ActivateWindow->setMinimumSize(QSize(553, 151));
        ActivateWindow->setMaximumSize(QSize(553, 151));
        gridLayout = new QGridLayout(ActivateWindow);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(ActivateWindow);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        prodkey_lineEdit = new QLineEdit(groupBox);
        prodkey_lineEdit->setObjectName("prodkey_lineEdit");
        prodkey_lineEdit->setMinimumSize(QSize(346, 26));
        prodkey_lineEdit->setMaximumSize(QSize(346, 26));
        prodkey_lineEdit->setMaxLength(40);

        formLayout->setWidget(0, QFormLayout::FieldRole, prodkey_lineEdit);

        checkPK_pushButton = new QPushButton(groupBox);
        checkPK_pushButton->setObjectName("checkPK_pushButton");

        formLayout->setWidget(1, QFormLayout::SpanningRole, checkPK_pushButton);

        checkPK_label = new QLabel(groupBox);
        checkPK_label->setObjectName("checkPK_label");

        formLayout->setWidget(2, QFormLayout::SpanningRole, checkPK_label);


        horizontalLayout->addLayout(formLayout);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ActivateWindow);

        QMetaObject::connectSlotsByName(ActivateWindow);
    } // setupUi

    void retranslateUi(QWidget *ActivateWindow)
    {
        ActivateWindow->setWindowTitle(QCoreApplication::translate("ActivateWindow", "Activation", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ActivateWindow", "\320\220\320\272\321\202\320\270\320\262\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213:", nullptr));
        label->setText(QCoreApplication::translate("ActivateWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\320\264 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260:", nullptr));
        prodkey_lineEdit->setText(QString());
        checkPK_pushButton->setText(QCoreApplication::translate("ActivateWindow", "\320\220\320\272\321\202\320\270\320\262\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        checkPK_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ActivateWindow: public Ui_ActivateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVATEWINDOW_H
