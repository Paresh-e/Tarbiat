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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortGroups
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
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
        textBrowser = new QTextBrowser(SortGroups);
        textBrowser->setObjectName("textBrowser");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(textBrowser);

        tableWidget = new QTableWidget(SortGroups);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
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
        textBrowser->setHtml(QCoreApplication::translate("SortGroups", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">\330\257\330\261 \330\254\330\257\331\210\331\204 \330\262\333\214\330\261 \332\257\330\261\331\210\331\207 \331\207\330\247\333\214 \331\205\330\263\330\247\330\250\331\202\331\207 \331\202\330\261\330\247\330\261 \330\257\330\247\330\261\330\257 . </span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">\331\204\330\267\331\201\330\247\331\213 \330\252\330\261\330\252\333\214\330\250 \331\205\330\257 \331\206\330\270\330\261 \330\256\331\210\330\257 \330\250\330\261\330\247\333\214 \330\264\330\261\331\210\330\271 \331\205\330\263\330\247\330\250\331\202\330\247\330\252 \330\261\330\247 \330\257\330\261 \330\250\330\247\332\251\330\263 \331\207\330\247\333\214 \331\207\330\261 \330\261\330\257\333\214\331\201 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257</span></p>\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt; font-weight:700;\"><br /></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SortGroups", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SortGroups", "Tatami", nullptr));
        pushButton->setText(QCoreApplication::translate("SortGroups", "save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortGroups: public Ui_SortGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTGROUPS_H
