#ifndef TIMETABLESETTINGS_H
#define TIMETABLESETTINGS_H

#include "qdatetime.h"
#include <QWidget>

namespace Ui {
class timeTableSettings;
}

class timeTableSettings : public QWidget
{
    Q_OBJECT

public:
    explicit timeTableSettings(QWidget *parent = nullptr);
    ~timeTableSettings();
    QMap<QString,QPair<QTime, QTime>> getRestTimes() const;
    int tatamiNumber;
    QTime startCom;

    bool repeCharge;
    bool beforeFinal;
    bool TimeForTattami= true;
    void set_restTimes(QMap<QString,QPair<QTime, QTime>> T);


private slots:
    void on_AddBreak_clicked();

    void on_DeleteBreakButton_clicked();

    void on_SaveButton_clicked();

    void on_SortGroupBtn_clicked();



    void on_repeCharCheackBox_stateChanged(int arg1);



    void on_TimeSetterCB_stateChanged(int arg1);

private:
    Ui::timeTableSettings *ui;
    QMap<QString,QPair<QTime, QTime>> currentRestTimes;
    void updateRestTimeList();
    bool isTimeOverlap(const QTime &newStart, const QTime &newEnd);
};

#endif // TIMETABLESETTINGS_H
