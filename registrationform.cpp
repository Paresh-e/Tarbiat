#include "registrationform.h"
#include "ui_registrationform.h"
#include <QMessageBox>
#include <QComboBox>
QString toStringComp(const CompetitionGroup& c) {
    return QString("%1\t| %2\t | %3kg\t | %4\t | %5 | %6")
    .arg(c.gender == Gender::Male ? "Male" : "Female")
        .arg(c.ageCategory)
            .arg(c.weightCategory)
                .arg(c.matchType == MatchType::Kata ? "Kata" : "Kumite")
                    .arg(c.entryType == EntryType::Team ? "Team" : "Individual")
                        .arg(c.matchDuration);
}
RegistrationForm::RegistrationForm(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::RegistrationForm),
    manager("groups.json")
{
    ui->setupUi(this);

    // Hide team-related widgets initially
    ui->teamTableWidget->setVisible(false);


    // Connect signals
    connect(ui->groupComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &RegistrationForm::onGroupChanged);

    connect(ui->registerButton, &QPushButton::clicked,
            this, &RegistrationForm::onRegisterClicked);


    manager.load();

    updateGroupList();

}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}

void RegistrationForm::updateGroupList()
{
    ui->groupComboBox->clear();

    manager.load(); // ← این خط خیلی مهمه

    QVector<CompetitionGroup> groups = manager.getGroups();
    for (const CompetitionGroup& group : groups) {
        ui->groupComboBox->addItem(toStringComp(group));
    }
}


void RegistrationForm::onGroupChanged(int index)
{
    if (index < 0) return;

    CompetitionGroup group = manager.getGroups().at(index);
    bool isTeam = group.entryType == EntryType::Team;
    if(isTeam){
        ui->mad->setText("Team Name:");
        ui->LastNameLineEdit->setVisible(false);
        ui->teamTableWidget->setRowCount(0);
        ui->teamTableWidget->setVisible(true);
        ui->label_4->setVisible(false);
        for(int i = 0 ; i < group.teamSize;i++){
            ui->teamTableWidget->insertRow(i);
            ui->teamTableWidget->setItem(i,0,new QTableWidgetItem("Name"));
            ui->teamTableWidget->setItem(i,1,new QTableWidgetItem("lastName"));
        }
    }else{
        ui->label_4->setVisible(true);
        ui->mad->setText("Name:");
        ui->LastNameLineEdit->setVisible(true);
        ui->teamTableWidget->setVisible(false);
    }
}

bool operator==(const CompetitionGroup& a, const CompetitionGroup& b) {
    return a.ageCategory == b.ageCategory &&
           a.weightCategory == b.weightCategory &&
           a.gender == b.gender &&
           a.matchType == b.matchType &&
           a.entryType == b.entryType;
}



void RegistrationForm::onRegisterClicked()
{

    QVector<CompetitionGroup> groups = manager.getGroups();
    CompetitionGroup& group = groups[ui->groupComboBox->currentIndex()];
    if(group.entryType==EntryType::Team){
        if(ui->nameLineEdit->text().isEmpty()||
            ui->groupComboBox->currentIndex()<0){
            QMessageBox::warning(this,"Error","teamtitle or group is empty");
        }
        Team newteam;
        newteam.teamName = ui->nameLineEdit->text();
        for (const Team& team : group.teams) {
            if (team.teamName == newteam.teamName) {
                QMessageBox::warning(this, "Duplicate", "Team already exists!");
                return;
            }
        }
        Participant newp;
        for(int i=0;i<group.teamSize;i++){

            newp.firstName= ui->teamTableWidget->item(i,0)->text();



            newp.lastName = ui->teamTableWidget->item(i,1)->text();


            newteam.members.push_back(newp);
        }

        group.teams.append(newteam);
        clearForm();
        manager.setGroups(groups);
    }else{
        if(ui->nameLineEdit->text().isEmpty() || ui->LastNameLineEdit->text().isEmpty() ||
            ui->groupComboBox->currentIndex()<0){
            QMessageBox::warning(this,"Error","name or lastname or teamtitle or group is empty");
            return;
        }
        Participant pnew;
        pnew.firstName = ui->nameLineEdit->text();
        pnew.lastName = ui ->LastNameLineEdit->text();
        group.participants.append(pnew);
        clearForm();
        manager.setGroups(groups);
    }
}

void RegistrationForm::clearForm()
{
    ui->nameLineEdit->clear();

    ui->teamTableWidget->setRowCount(0);
    ui->LastNameLineEdit->clear();
    onGroupChanged(ui->groupComboBox->currentIndex());
}


