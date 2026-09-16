#include "mainwindow.h"
#include "globaldata.h"
#include "timetable.h"
#include "ui_mainwindow.h"
#include "timetablesettings.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCompetitionGroups_clicked()
{
    CompetitionGroupForm *form = new CompetitionGroupForm(this);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
}

void MainWindow::on_btnRegisterParticipant_clicked()
{
    RegistrationForm *form = new RegistrationForm(this);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
}

void MainWindow::on_btnViewRegistrations_clicked()
{
    CompetitionGroupManager *manger = new CompetitionGroupManager(QCoreApplication::applicationDirPath() + "/groups.json");
    RegistrationListForm *form = new RegistrationListForm(manger,this);

    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
}





void MainWindow::on_TimeTableSettingsButton_clicked()
{
    timeTableSettings *form = new timeTableSettings(nullptr);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();
}


void MainWindow::on_TimeTableButton_clicked()
{
    TimeTable* form = new TimeTable(nullptr);
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->show();

}

