/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnCompetitionGroups;
    QPushButton *btnRegisterParticipant;
    QSpacerItem *verticalSpacer;
    QPushButton *TimeTableSettingsButton;
    QPushButton *TimeTableButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnViewRegistrations;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 699);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        btnCompetitionGroups = new QPushButton(centralwidget);
        btnCompetitionGroups->setObjectName("btnCompetitionGroups");

        verticalLayout->addWidget(btnCompetitionGroups);

        btnRegisterParticipant = new QPushButton(centralwidget);
        btnRegisterParticipant->setObjectName("btnRegisterParticipant");

        verticalLayout->addWidget(btnRegisterParticipant);

        verticalSpacer = new QSpacerItem(20, 350, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        TimeTableSettingsButton = new QPushButton(centralwidget);
        TimeTableSettingsButton->setObjectName("TimeTableSettingsButton");

        verticalLayout->addWidget(TimeTableSettingsButton);

        TimeTableButton = new QPushButton(centralwidget);
        TimeTableButton->setObjectName("TimeTableButton");

        verticalLayout->addWidget(TimeTableButton);

        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnViewRegistrations = new QPushButton(centralwidget);
        btnViewRegistrations->setObjectName("btnViewRegistrations");

        horizontalLayout->addWidget(btnViewRegistrations);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnCompetitionGroups->setText(QCoreApplication::translate("MainWindow", "Group Panel", nullptr));
        btnRegisterParticipant->setText(QCoreApplication::translate("MainWindow", "Register Panel", nullptr));
        TimeTableSettingsButton->setText(QCoreApplication::translate("MainWindow", "TimeTableSettings", nullptr));
        TimeTableButton->setText(QCoreApplication::translate("MainWindow", "TimeTable", nullptr));
        btnViewRegistrations->setText(QCoreApplication::translate("MainWindow", "View Registerd Panel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
