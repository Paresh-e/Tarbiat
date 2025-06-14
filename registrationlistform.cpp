// RegistrationListForm.cpp
#include "RegistrationListForm.h"
#include "ui_RegistrationListForm.h"
#include <QPushButton>
RegistrationListForm::RegistrationListForm(CompetitionGroupManager* manager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegistrationListForm)
    , manager(manager)
{
    treeWidget = new QTreeWidget();
    ui->setupUi(this);
    ui->verticalLayout->insertWidget(0,treeWidget);
    QPushButton* deleteButton = new QPushButton("Delete Selected");
    ui->verticalLayout->addWidget(deleteButton);
    connect(deleteButton, &QPushButton::clicked, this, &RegistrationListForm::onDeleteClicked);

    manager->load();
    populateData();
}
void RegistrationListForm::onDeleteClicked()
{
    QTreeWidgetItem* selectedItem = treeWidget->currentItem();
    if (!selectedItem) return;

    // Top-level: گروه
    if (!selectedItem->parent() ||selectedItem->parent()->parent() ) return;


    else if (selectedItem->text(0).startsWith("Team: ")) {
        // خود تیم انتخاب شده
        QString groupLabel = selectedItem->parent()->text(0);
        qDebug()<<groupLabel;
        QString teamName = selectedItem->text(0).mid(6);

        manager->removeTeam(groupLabel, teamName);
    }
    else if (selectedItem->text(0).startsWith("Individual - ")) {
        // فرد ثبت‌نامی انفرادی
        QString groupLabel = selectedItem->parent()->text(0);
        QString fullName = selectedItem->text(0).mid(13);
        QStringList nameParts = fullName.split(' ');
        if (nameParts.size() >= 2) {
            QString firstName = nameParts[0];
            QString lastName = nameParts[1];

            manager->removeIndividualParticipant(groupLabel, firstName, lastName);
        }
    }

    manager->save();
    populateData();
}

RegistrationListForm::~RegistrationListForm()
{
    delete ui;
}

void RegistrationListForm::populateData()
{

    treeWidget->clear();
    treeWidget->setHeaderLabels(QStringList() << "Registration Info");

    const QVector<CompetitionGroup>& groups = manager->getGroups();

    for (const CompetitionGroup& group : groups)
    {
        QString groupLabel = QString("Group - Age: %1 | Weight: %2 | Gender: %3 | MatchType: %4 | MatchDuration: %5")
        .arg(group.ageCategory)
            .arg(group.weightCategory)
                .arg(group.gender == Gender::Male ? "Male" : "Female")
                    .arg(group.matchType == MatchType::Kata ? "Kata" : "Kumite")
                        .arg(group.matchDuration);

        QTreeWidgetItem* groupItem = new QTreeWidgetItem(QStringList() << groupLabel);
        treeWidget->addTopLevelItem(groupItem);

        if (group.entryType == EntryType::Individual)
        {
            for (const Participant& p : group.participants)
            {
                QString name = QString("Individual - %1 %2").arg(p.firstName, p.lastName);
                QTreeWidgetItem* participantItem = new QTreeWidgetItem(QStringList() << name);
                groupItem->addChild(participantItem);
            }
        }
        else // EntryType::Team
        {
            for (const Team& team : group.teams)
            {
                QTreeWidgetItem* teamItem = new QTreeWidgetItem(QStringList() << "Team: " + team.teamName);
                groupItem->addChild(teamItem);

                for (const Participant& member : team.members)
                {
                    QString memberName = QString("%1 %2").arg(member.firstName, member.lastName);
                    QTreeWidgetItem* memberItem = new QTreeWidgetItem(QStringList() << memberName);
                    teamItem->addChild(memberItem);
                }
            }
        }


    }
    treeWidget->resizeColumnToContents(0);
}
