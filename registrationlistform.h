
// RegistrationListForm.h
#pragma once
#include <QTreeWidget>
#include <QWidget>
#include <QTableWidget>
#include "CompetitionGroupManager.h"
#include<QDialog>
namespace Ui {
class RegistrationListForm;
}

class RegistrationListForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationListForm(CompetitionGroupManager* manager, QWidget *parent = nullptr);
    ~RegistrationListForm();

    void populateData();
    void onDeleteClicked();

private:
    Ui::RegistrationListForm *ui;
    CompetitionGroupManager* manager;
    QTreeWidget * treeWidget;
    QPushButton* deleteButton ;
};


