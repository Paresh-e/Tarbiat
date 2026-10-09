/********************************************************************************
** Form generated from reading UI file 'competitiongroupform.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPETITIONGROUPFORM_H
#define UI_COMPETITIONGROUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CompetitionGroupForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *AgeLabel;
    QLineEdit *ageLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *weightLabel;
    QLineEdit *weightLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *GenderLabel;
    QComboBox *genderComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *matchTypeLabel;
    QComboBox *matchTypeComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *matchDurationLable;
    QDoubleSpinBox *matchDurationDoubleSpinBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *entryTypeLabel;
    QComboBox *entryTypeComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *teamSizeLabel;
    QSpinBox *teamSizeSpinBox;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *deleteButton;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout_10;
    QLabel *spaceLable;
    QDoubleSpinBox *spaceDoubleSpinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *groupTable;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *CompetitionGroupForm)
    {
        if (CompetitionGroupForm->objectName().isEmpty())
            CompetitionGroupForm->setObjectName("CompetitionGroupForm");
        CompetitionGroupForm->resize(900, 750);
        verticalLayout = new QVBoxLayout(CompetitionGroupForm);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        AgeLabel = new QLabel(CompetitionGroupForm);
        AgeLabel->setObjectName("AgeLabel");

        horizontalLayout_2->addWidget(AgeLabel);

        ageLineEdit = new QLineEdit(CompetitionGroupForm);
        ageLineEdit->setObjectName("ageLineEdit");

        horizontalLayout_2->addWidget(ageLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        weightLabel = new QLabel(CompetitionGroupForm);
        weightLabel->setObjectName("weightLabel");

        horizontalLayout_3->addWidget(weightLabel);

        weightLineEdit = new QLineEdit(CompetitionGroupForm);
        weightLineEdit->setObjectName("weightLineEdit");

        horizontalLayout_3->addWidget(weightLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        GenderLabel = new QLabel(CompetitionGroupForm);
        GenderLabel->setObjectName("GenderLabel");

        horizontalLayout_4->addWidget(GenderLabel);

        genderComboBox = new QComboBox(CompetitionGroupForm);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");

        horizontalLayout_4->addWidget(genderComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        matchTypeLabel = new QLabel(CompetitionGroupForm);
        matchTypeLabel->setObjectName("matchTypeLabel");

        horizontalLayout_5->addWidget(matchTypeLabel);

        matchTypeComboBox = new QComboBox(CompetitionGroupForm);
        matchTypeComboBox->addItem(QString());
        matchTypeComboBox->addItem(QString());
        matchTypeComboBox->setObjectName("matchTypeComboBox");

        horizontalLayout_5->addWidget(matchTypeComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        matchDurationLable = new QLabel(CompetitionGroupForm);
        matchDurationLable->setObjectName("matchDurationLable");

        horizontalLayout_6->addWidget(matchDurationLable);

        matchDurationDoubleSpinBox = new QDoubleSpinBox(CompetitionGroupForm);
        matchDurationDoubleSpinBox->setObjectName("matchDurationDoubleSpinBox");
        matchDurationDoubleSpinBox->setDecimals(1);
        matchDurationDoubleSpinBox->setMinimum(0.500000000000000);
        matchDurationDoubleSpinBox->setMaximum(20.000000000000000);
        matchDurationDoubleSpinBox->setSingleStep(0.500000000000000);
        matchDurationDoubleSpinBox->setValue(1.000000000000000);

        horizontalLayout_6->addWidget(matchDurationDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        entryTypeLabel = new QLabel(CompetitionGroupForm);
        entryTypeLabel->setObjectName("entryTypeLabel");

        horizontalLayout_9->addWidget(entryTypeLabel);

        entryTypeComboBox = new QComboBox(CompetitionGroupForm);
        entryTypeComboBox->addItem(QString());
        entryTypeComboBox->addItem(QString());
        entryTypeComboBox->setObjectName("entryTypeComboBox");

        horizontalLayout_9->addWidget(entryTypeComboBox);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        teamSizeLabel = new QLabel(CompetitionGroupForm);
        teamSizeLabel->setObjectName("teamSizeLabel");

        horizontalLayout_7->addWidget(teamSizeLabel);

        teamSizeSpinBox = new QSpinBox(CompetitionGroupForm);
        teamSizeSpinBox->setObjectName("teamSizeSpinBox");
        teamSizeSpinBox->setMinimum(2);
        teamSizeSpinBox->setMaximum(20);

        horizontalLayout_7->addWidget(teamSizeSpinBox);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        deleteButton = new QPushButton(CompetitionGroupForm);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_8->addWidget(deleteButton);

        addButton = new QPushButton(CompetitionGroupForm);
        addButton->setObjectName("addButton");

        horizontalLayout_8->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        spaceLable = new QLabel(CompetitionGroupForm);
        spaceLable->setObjectName("spaceLable");

        horizontalLayout_10->addWidget(spaceLable);

        spaceDoubleSpinBox = new QDoubleSpinBox(CompetitionGroupForm);
        spaceDoubleSpinBox->setObjectName("spaceDoubleSpinBox");
        spaceDoubleSpinBox->setDecimals(1);
        spaceDoubleSpinBox->setSingleStep(1.000000000000000);
        spaceDoubleSpinBox->setValue(0.000000000000000);

        horizontalLayout_10->addWidget(spaceDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_10);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(83, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        groupTable = new QTableWidget(CompetitionGroupForm);
        if (groupTable->columnCount() < 8)
            groupTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        groupTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        groupTable->setObjectName("groupTable");

        horizontalLayout->addWidget(groupTable);

        horizontalSpacer = new QSpacerItem(83, 1, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CompetitionGroupForm);

        QMetaObject::connectSlotsByName(CompetitionGroupForm);
    } // setupUi

    void retranslateUi(QDialog *CompetitionGroupForm)
    {
        CompetitionGroupForm->setWindowTitle(QCoreApplication::translate("CompetitionGroupForm", "Dialog", nullptr));
        AgeLabel->setText(QCoreApplication::translate("CompetitionGroupForm", "Age:", nullptr));
        weightLabel->setText(QCoreApplication::translate("CompetitionGroupForm", "weight", nullptr));
        GenderLabel->setText(QCoreApplication::translate("CompetitionGroupForm", "Gender:", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("CompetitionGroupForm", "Male", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("CompetitionGroupForm", "Female", nullptr));

        matchTypeLabel->setText(QCoreApplication::translate("CompetitionGroupForm", "matchType", nullptr));
        matchTypeComboBox->setItemText(0, QCoreApplication::translate("CompetitionGroupForm", "Kata", nullptr));
        matchTypeComboBox->setItemText(1, QCoreApplication::translate("CompetitionGroupForm", "Kumite", nullptr));

        matchDurationLable->setText(QCoreApplication::translate("CompetitionGroupForm", "matchDuration(min)", nullptr));
        entryTypeLabel->setText(QCoreApplication::translate("CompetitionGroupForm", "entryType:", nullptr));
        entryTypeComboBox->setItemText(0, QCoreApplication::translate("CompetitionGroupForm", "Team", nullptr));
        entryTypeComboBox->setItemText(1, QCoreApplication::translate("CompetitionGroupForm", "Individual", nullptr));

        teamSizeLabel->setText(QCoreApplication::translate("CompetitionGroupForm", "TeamSize:", nullptr));
        deleteButton->setText(QCoreApplication::translate("CompetitionGroupForm", "DeleteGroup", nullptr));
        addButton->setText(QCoreApplication::translate("CompetitionGroupForm", "AddGroup", nullptr));
        spaceLable->setText(QCoreApplication::translate("CompetitionGroupForm", "space(min)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = groupTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CompetitionGroupForm", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = groupTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CompetitionGroupForm", "weight", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = groupTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CompetitionGroupForm", "Gender", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = groupTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CompetitionGroupForm", "matchType", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = groupTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CompetitionGroupForm", "matchDuration", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = groupTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CompetitionGroupForm", "EntryType", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = groupTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CompetitionGroupForm", "TeamSize", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = groupTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CompetitionGroupForm", "space", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompetitionGroupForm: public Ui_CompetitionGroupForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPETITIONGROUPFORM_H
