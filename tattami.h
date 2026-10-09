#ifndef TATTAMI_H
#define TATTAMI_H
#include <QString>





#include "competitiongroup.h"



class Tattami
{
public:
    Tattami();
    Tattami(QString,QTime = QTime(8,0,0));
    QString Title;
    QMap<int,CompetitionGroup> Cat;
    QTime Last ;

    void set_Category(CompetitionGroup &);

};

#endif // TATTAMI_H
