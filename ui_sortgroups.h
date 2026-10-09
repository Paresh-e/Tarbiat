/********************************************************************************
** Form generated from reading UI file 'sortgroups.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTGROUPS_H
#define UI_SORTGROUPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortGroups
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *SortGroups)
    {
        if (SortGroups->objectName().isEmpty())
            SortGroups->setObjectName("SortGroups");
        SortGroups->resize(900, 750);
        SortGroups->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        verticalLayout = new QVBoxLayout(SortGroups);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(SortGroups);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragEnabled(true);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setDragDropMode(QAbstractItemView::DragDropMode::NoDragDrop);
        tableWidget->setDefaultDropAction(Qt::DropAction::IgnoreAction);
        tableWidget->horizontalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);

        pushButton = new QPushButton(SortGroups);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(SortGroups);

        QMetaObject::connectSlotsByName(SortGroups);
    } // setupUi

    void retranslateUi(QDialog *SortGroups)
    {
        SortGroups->setWindowTitle(QCoreApplication::translate("SortGroups", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SortGroups", "save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortGroups: public Ui_SortGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTGROUPS_H
