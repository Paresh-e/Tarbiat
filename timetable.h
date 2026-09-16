#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "competitiongroupmanager.h"
#include "timetablesettings.h"
#include <QWidget>

namespace Ui {
class TimeTable;
}

class TimeTable : public QWidget
{
    Q_OBJECT

public:
    explicit TimeTable(QWidget *parent = nullptr);
    ~TimeTable();
    void populateTable();

    void exportToPdf();

    QString groupDescription(const CompetitionGroup& grou) const ;




    void putLable_Kata_Team(const CompetitionGroup &c);
    void putLable_Kata_Indivi(const CompetitionGroup& c);
    void putLable_Kumi_Team(const CompetitionGroup& c);
    void putLable_Kumi_Indivi(const CompetitionGroup& c);
    void set_Item(QString a,int row , int co);


    QMap<QString,QTime> Current_tatami_Time;
    QVector<QString> *tatami_Names;

    QPair<QString,QTime> finad_tatmi(QString , double space);

    QMap<QString, QPair<QTime, QTime>> *restTimes;


    void where_compGro_go(const CompetitionGroup&, QString tatmi, double space, double Durat);
    void nextRound(QVector<QString>&, QString tatami, double space, double Durat);
    void pop_Kata(QVector<QString> &p, QString tatami, double space, double Durat);
    void pop_Kumi(QVector<QString> &p, QString tatami, double space, double Durat);
private slots:
    // void on_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::TimeTable *ui;
    timeTableSettings * mySettings;
    QMap<QString,QMap<int,CompetitionGroup>> *MyGroups;

};

#endif // TIMETABLE_H
