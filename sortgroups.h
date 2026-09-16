#ifndef SORTGROUPS_H
#define SORTGROUPS_H

#include "competitiongroupmanager.h"
#include "qcombobox.h"
#include <QDialog>

namespace Ui {
class SortGroups;
}

class SortGroups : public QDialog
{
    Q_OBJECT

public:
    explicit SortGroups(QWidget *parent = nullptr,int tatami = 1);
    ~SortGroups();
    QVector<QComboBox*> *tatami;
    QVector<QComboBox *> *order;
    QMap<QString,QSet<int>> usedOrders;
    QVector<QString> currentTatami;       // حرف انتخابی هر ردیف
    QVector<int> currentOrder;

    void updateOrderComboForRow(int row);
private slots:
    void on_pushButton_clicked();
    // void handleComboBox_orderIndexChanged(int row, int new_index,QComboBox *changedComboBox);
    // void handleComboBox_tatamiChanged(int row, const QString &newText, QComboBox *changedComboBox);
private:
    Ui::SortGroups *ui;
    CompetitionGroupManager manager;
};

#endif // SORTGROUPS_H
