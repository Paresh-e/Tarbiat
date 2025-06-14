#ifndef COMPETITIONGROUP_H
#define COMPETITIONGROUP_H




#include <QString>
#include <QStringList>
#include <QJsonObject>
#include <QJsonArray>



enum class Gender { Male, Female };
enum class MatchType { Kata, Kumite };
enum class EntryType { Individual, Team };
struct Participant {
    QString firstName;
    QString lastName;

};

struct Team {
    QString teamName;
    QVector<Participant> members;
};

struct CompetitionGroup {

    QString ageCategory;
    QString weightCategory;
    Gender gender;

    MatchType matchType;
    double matchDuration;
    EntryType entryType;
    QVector<Participant> participants;
    QVector<Team> teams;
    QJsonObject toJson() const ;

    int teamSize; // صفر برای انفرادی
};



#endif // COMPETITIONGROUP_H
