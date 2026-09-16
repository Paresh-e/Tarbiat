#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include "competitiongroup.h"
#include "timetablesettings.h"
class GlobalData
{
public:
    static GlobalData& instance(){
        static GlobalData instance;
        return instance;
    }
    int number_of_this_group_participant;
    int repe_Done = 0 ;
    timeTableSettings TTS ;
    QMap<QString,QMap<int,CompetitionGroup>>  finalGroups;
    void SetGroups(QMap<QString,QMap<int,CompetitionGroup>> & G){
        for (auto it = G.constBegin(); it != G.constEnd(); ++it) {
            QMap<int, CompetitionGroup> innerMap;
            for (auto innerIt = it.value().constBegin(); innerIt != it.value().constEnd(); ++innerIt) {
                innerMap.insert(innerIt.key(), innerIt.value()); // کپی CompetitionGroup
            }

            finalGroups.insert(it.key(), innerMap);
        }

    }
    void Describefinal(){
        for (auto it = finalGroups.constBegin(); it != finalGroups.constEnd(); ++it) {
            QMap<int, CompetitionGroup> innerMap;
            for (auto innerIt = it.value().constBegin(); innerIt != it.value().constEnd(); ++innerIt) {

                // qDebug()<<it.key()<<":"<<innerIt.key()<<":"<<innerIt.value().ageCategory;
            }
        }
    }
    void empty_finalGroups(){
        finalGroups.clear();
    }
    bool isfull = false;
    void SetSettings(timeTableSettings& T ){
        TTS.repeCharge = T.repeCharge;
        TTS.beforeFinal = T.beforeFinal;
        TTS.tatamiNumber = T.tatamiNumber;
        TTS.startCom =T.startCom;
        TTS.set_restTimes(T.getRestTimes());
        isfull = true;
    }
private:
    GlobalData(){}
    GlobalData(const GlobalData&)= delete;
    };


#endif // GLOBALDATA_H
