/********************************************************************************
** Form generated from reading UI file 'registrationlistform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONLISTFORM_H
#define UI_REGISTRATIONLISTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegistrationListForm
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *RegistrationListForm)
    {
        if (RegistrationListForm->objectName().isEmpty())
            RegistrationListForm->setObjectName("RegistrationListForm");
        RegistrationListForm->resize(900, 750);
        verticalLayout = new QVBoxLayout(RegistrationListForm);
        verticalLayout->setObjectName("verticalLayout");

        retranslateUi(RegistrationListForm);

        QMetaObject::connectSlotsByName(RegistrationListForm);
    } // setupUi

    void retranslateUi(QDialog *RegistrationListForm)
    {
        RegistrationListForm->setWindowTitle(QCoreApplication::translate("RegistrationListForm", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationListForm: public Ui_RegistrationListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONLISTFORM_H
