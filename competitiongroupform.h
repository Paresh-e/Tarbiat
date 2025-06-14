// CompetitionGroupForm.h
#ifndef COMPETITIONGROUPFORM_H
#define COMPETITIONGROUPFORM_H


#include <QWidget>

#include "competitiongroupmanager.h"

namespace Ui {
class CompetitionGroupForm;
}
#include "ui_competitiongroupform.h"
class CompetitionGroupForm : public QDialog
{
    Q_OBJECT

public:
    explicit CompetitionGroupForm(QWidget *parent = nullptr);
    ~CompetitionGroupForm();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();

    void on_entryTypeComboBox_activated(int index);

private:
    void loadGroups();
    void clear();
    void refreshTable();

    Ui::CompetitionGroupForm *ui;
    CompetitionGroupManager manager;
};

#endif // COMPETITIONGROUPFORM_H
