/********************************************************************************
** Form generated from reading UI file 'registrationform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONFORM_H
#define UI_REGISTRATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegistrationForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *groupComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mad;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *LastNameLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *teamTableWidget;
    QSpacerItem *horizontalSpacer;
    QPushButton *registerButton;

    void setupUi(QDialog *RegistrationForm)
    {
        if (RegistrationForm->objectName().isEmpty())
            RegistrationForm->setObjectName("RegistrationForm");
        RegistrationForm->resize(900, 750);
        verticalLayout_2 = new QVBoxLayout(RegistrationForm);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(RegistrationForm);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        groupComboBox = new QComboBox(RegistrationForm);
        groupComboBox->setObjectName("groupComboBox");

        horizontalLayout->addWidget(groupComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        mad = new QLabel(RegistrationForm);
        mad->setObjectName("mad");

        horizontalLayout_2->addWidget(mad);

        nameLineEdit = new QLineEdit(RegistrationForm);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout_2->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(RegistrationForm);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        LastNameLineEdit = new QLineEdit(RegistrationForm);
        LastNameLineEdit->setObjectName("LastNameLineEdit");

        horizontalLayout_3->addWidget(LastNameLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 120, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_2 = new QSpacerItem(335, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        teamTableWidget = new QTableWidget(RegistrationForm);
        if (teamTableWidget->columnCount() < 2)
            teamTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        teamTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        teamTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        teamTableWidget->setObjectName("teamTableWidget");

        horizontalLayout_5->addWidget(teamTableWidget);

        horizontalSpacer = new QSpacerItem(335, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_5);

        registerButton = new QPushButton(RegistrationForm);
        registerButton->setObjectName("registerButton");

        verticalLayout_2->addWidget(registerButton);


        retranslateUi(RegistrationForm);

        QMetaObject::connectSlotsByName(RegistrationForm);
    } // setupUi

    void retranslateUi(QDialog *RegistrationForm)
    {
        RegistrationForm->setWindowTitle(QCoreApplication::translate("RegistrationForm", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegistrationForm", "MatchGroup", nullptr));
        mad->setText(QCoreApplication::translate("RegistrationForm", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("RegistrationForm", "LastName", nullptr));
        QTableWidgetItem *___qtablewidgetitem = teamTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RegistrationForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = teamTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RegistrationForm", "LastName", nullptr));
        registerButton->setText(QCoreApplication::translate("RegistrationForm", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationForm: public Ui_RegistrationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONFORM_H
