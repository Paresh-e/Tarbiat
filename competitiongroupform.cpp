// CompetitionGroupForm.cpp
#include "competitiongroup.h"
#include"competitiongroupform.h"
#include "ui_competitiongroupform.h"
#include <QMessageBox>
CompetitionGroupForm::CompetitionGroupForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompetitionGroupForm),
    manager(QCoreApplication::applicationDirPath() + "/groups.json")
{
    ui->setupUi(this);
    ui->weightLabel->setVisible(false);
    ui->weightLineEdit->setVisible(false);
    loadGroups();
    refreshTable();
}
CompetitionGroupForm::~CompetitionGroupForm()
{

    delete ui;
}

void CompetitionGroupForm::loadGroups() {
    manager.load();
}



void CompetitionGroupForm::refreshTable() {
    ui->groupTable->setRowCount(0);
    const auto& groups = manager.getGroups();
    for (int i = 0; i < groups.size(); ++i) {
        const auto& g = groups[i];
        ui->groupTable->insertRow(i);
        ui->groupTable->setItem(i, 0, new QTableWidgetItem(g.ageCategory));
        ui->groupTable->setItem(i, 1, new QTableWidgetItem(g.weightCategory));
        ui->groupTable->setItem(i, 2, new QTableWidgetItem(g.gender == Gender::Male ? "Male" : "Female"));
        ui->groupTable->setItem(i, 3, new QTableWidgetItem(g.matchType == MatchType::Kata ? "Kata" : "Kumite"));
        ui->groupTable->setItem(i, 4, new QTableWidgetItem(QString::number(g.matchDuration)));
        ui->groupTable->setItem(i, 5, new QTableWidgetItem(g.entryType == EntryType::Team ? "Team" : "Individual"));
        ui->groupTable->setItem(i, 6, new QTableWidgetItem(QString::number(g.teamSize)));
        ui->groupTable->setItem(i, 7, new QTableWidgetItem(QString::number(g.Space)));
    }
}

void CompetitionGroupForm::on_addButton_clicked()
{


    CompetitionGroup g;
    g.ageCategory = ui->ageLineEdit->text();

    g.gender = (ui->genderComboBox->currentText() == "Male") ? Gender::Male : Gender::Female;
    g.matchType = (ui->matchTypeComboBox->currentText() == "Kata") ? MatchType::Kata : MatchType::Kumite;
    if(g.matchType == MatchType::Kata){
        g.weightCategory = "-";
    }else{
        g.weightCategory = ui->weightLineEdit->text();
    }
    g.entryType = (ui->entryTypeComboBox->currentText() == "Team") ? EntryType::Team : EntryType::Individual;
    g.teamSize = g.entryType == EntryType::Team ? ui->teamSizeSpinBox->value() : 0;
    g.matchDuration = ui->matchDurationDoubleSpinBox->value();
    g.Space = ui->spaceDoubleSpinBox->value();
    if (g.ageCategory.isEmpty() || g.weightCategory.isEmpty()) {
        QMessageBox::warning(this, "Error", "Age and weight category cannot be empty.");
        return;
    }
    manager.addGroup(g);
    refreshTable();
    clear();


}
void CompetitionGroupForm::clear(){
    ui->ageLineEdit->clear();
    ui->weightLineEdit->clear();

}
void CompetitionGroupForm::on_deleteButton_clicked()
{
    int row = ui->groupTable->currentRow();
    if (row >= 0) {
        manager.removeGroup(row);
        refreshTable();

    }
}


void CompetitionGroupForm::on_entryTypeComboBox_activated(int index)
{
    if(index == 1 ){
        ui->teamSizeLabel->setVisible(false);
        ui->teamSizeSpinBox->setVisible(false);

    }else{
        ui->teamSizeLabel->setVisible(true);
        ui->teamSizeSpinBox->setVisible(true);

    }
}


void CompetitionGroupForm::on_matchTypeComboBox_currentIndexChanged(int index)
{
    if(index==1){
        ui->weightLabel->setVisible(true);
        ui->weightLineEdit->setVisible(true);
    }else{
        ui->weightLabel->setVisible(false);
        ui->weightLineEdit->setVisible(false);
    }
}

