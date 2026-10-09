/********************************************************************************
** Form generated from reading UI file 'timetablesettings.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMETABLESETTINGS_H
#define UI_TIMETABLESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timeTableSettings
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *TatamiNumberLable;
    QSpinBox *TatamiNumberSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *StartTimeLable_2;
    QTimeEdit *StartTimeEdit;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *TimeSetterCB;
    QTimeEdit *DefaultTimeEdit;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *repeCharCheackBox;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *BreakStartTimeLable;
    QTimeEdit *BreakStartTimeEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *BreakEndTimeLable;
    QTimeEdit *BreakEndTimeEdit;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *AddBreak;
    QHBoxLayout *horizontalLayout_8;
    QListWidget *restTimeList;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *DeleteBreakButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *SortGroupBtn;
    QPushButton *SaveButton;

    void setupUi(QWidget *timeTableSettings)
    {
        if (timeTableSettings->objectName().isEmpty())
            timeTableSettings->setObjectName("timeTableSettings");
        timeTableSettings->resize(936, 750);
        verticalLayout_4 = new QVBoxLayout(timeTableSettings);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        TatamiNumberLable = new QLabel(timeTableSettings);
        TatamiNumberLable->setObjectName("TatamiNumberLable");

        horizontalLayout->addWidget(TatamiNumberLable);

        TatamiNumberSpinBox = new QSpinBox(timeTableSettings);
        TatamiNumberSpinBox->setObjectName("TatamiNumberSpinBox");
        TatamiNumberSpinBox->setMinimum(1);
        TatamiNumberSpinBox->setMaximum(25);

        horizontalLayout->addWidget(TatamiNumberSpinBox);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        StartTimeLable_2 = new QLabel(timeTableSettings);
        StartTimeLable_2->setObjectName("StartTimeLable_2");

        horizontalLayout_2->addWidget(StartTimeLable_2);

        StartTimeEdit = new QTimeEdit(timeTableSettings);
        StartTimeEdit->setObjectName("StartTimeEdit");
        StartTimeEdit->setMaximumDateTime(QDateTime(QDate(2000, 1, 1), QTime(23, 59, 59)));
        StartTimeEdit->setMaximumTime(QTime(23, 59, 59));
        StartTimeEdit->setTime(QTime(8, 0, 0));

        horizontalLayout_2->addWidget(StartTimeEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_4 = new QSpacerItem(700, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        TimeSetterCB = new QCheckBox(timeTableSettings);
        TimeSetterCB->setObjectName("TimeSetterCB");
        TimeSetterCB->setChecked(true);

        horizontalLayout_6->addWidget(TimeSetterCB);

        DefaultTimeEdit = new QTimeEdit(timeTableSettings);
        DefaultTimeEdit->setObjectName("DefaultTimeEdit");

        horizontalLayout_6->addWidget(DefaultTimeEdit);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        repeCharCheackBox = new QCheckBox(timeTableSettings);
        repeCharCheackBox->setObjectName("repeCharCheackBox");
        repeCharCheackBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        verticalLayout_3->addWidget(repeCharCheackBox);

        checkBox = new QCheckBox(timeTableSettings);
        checkBox->setObjectName("checkBox");

        verticalLayout_3->addWidget(checkBox);


        horizontalLayout_6->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        BreakStartTimeLable = new QLabel(timeTableSettings);
        BreakStartTimeLable->setObjectName("BreakStartTimeLable");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BreakStartTimeLable->sizePolicy().hasHeightForWidth());
        BreakStartTimeLable->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(BreakStartTimeLable);

        BreakStartTimeEdit = new QTimeEdit(timeTableSettings);
        BreakStartTimeEdit->setObjectName("BreakStartTimeEdit");
        BreakStartTimeEdit->setTime(QTime(8, 0, 0));

        horizontalLayout_4->addWidget(BreakStartTimeEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        BreakEndTimeLable = new QLabel(timeTableSettings);
        BreakEndTimeLable->setObjectName("BreakEndTimeLable");
        sizePolicy.setHeightForWidth(BreakEndTimeLable->sizePolicy().hasHeightForWidth());
        BreakEndTimeLable->setSizePolicy(sizePolicy);
        BreakEndTimeLable->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(BreakEndTimeLable);

        BreakEndTimeEdit = new QTimeEdit(timeTableSettings);
        BreakEndTimeEdit->setObjectName("BreakEndTimeEdit");
        BreakEndTimeEdit->setTime(QTime(8, 10, 0));

        horizontalLayout_3->addWidget(BreakEndTimeEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);

        label = new QLabel(timeTableSettings);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label);

        lineEdit = new QLineEdit(timeTableSettings);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit);

        AddBreak = new QPushButton(timeTableSettings);
        AddBreak->setObjectName("AddBreak");

        horizontalLayout_5->addWidget(AddBreak);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        restTimeList = new QListWidget(timeTableSettings);
        restTimeList->setObjectName("restTimeList");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        restTimeList->setFont(font);
        restTimeList->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_8->addWidget(restTimeList);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        DeleteBreakButton = new QPushButton(timeTableSettings);
        DeleteBreakButton->setObjectName("DeleteBreakButton");

        verticalLayout_2->addWidget(DeleteBreakButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_7->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(400, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        SortGroupBtn = new QPushButton(timeTableSettings);
        SortGroupBtn->setObjectName("SortGroupBtn");

        horizontalLayout_7->addWidget(SortGroupBtn);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(horizontalLayout_8);

        SaveButton = new QPushButton(timeTableSettings);
        SaveButton->setObjectName("SaveButton");

        verticalLayout_4->addWidget(SaveButton);


        retranslateUi(timeTableSettings);

        QMetaObject::connectSlotsByName(timeTableSettings);
    } // setupUi

    void retranslateUi(QWidget *timeTableSettings)
    {
        timeTableSettings->setWindowTitle(QCoreApplication::translate("timeTableSettings", "Form", nullptr));
        TatamiNumberLable->setText(QCoreApplication::translate("timeTableSettings", "tatamiNumber:", nullptr));
        StartTimeLable_2->setText(QCoreApplication::translate("timeTableSettings", "Start:", nullptr));
        StartTimeEdit->setDisplayFormat(QCoreApplication::translate("timeTableSettings", "h:mm AP", nullptr));
        TimeSetterCB->setText(QCoreApplication::translate("timeTableSettings", "DefaultTimeForTattami", nullptr));
        repeCharCheackBox->setText(QCoreApplication::translate("timeTableSettings", "\330\264\330\247\331\206\330\263 \331\205\330\254\330\257\330\257", nullptr));
        checkBox->setText(QCoreApplication::translate("timeTableSettings", "\331\202\330\250\331\204 \330\247\330\262 \331\201\333\214\331\206\330\247\331\204", nullptr));
        BreakStartTimeLable->setText(QCoreApplication::translate("timeTableSettings", "StartBreak", nullptr));
        BreakEndTimeLable->setText(QCoreApplication::translate("timeTableSettings", "EndBreak", nullptr));
        label->setText(QCoreApplication::translate("timeTableSettings", "BreackTitle:", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("timeTableSettings", "Launch", nullptr));
        AddBreak->setText(QCoreApplication::translate("timeTableSettings", "AddBreak", nullptr));
        DeleteBreakButton->setText(QCoreApplication::translate("timeTableSettings", "DeleteBreak", nullptr));
        SortGroupBtn->setText(QCoreApplication::translate("timeTableSettings", "GroupSort", nullptr));
        SaveButton->setText(QCoreApplication::translate("timeTableSettings", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class timeTableSettings: public Ui_timeTableSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMETABLESETTINGS_H
