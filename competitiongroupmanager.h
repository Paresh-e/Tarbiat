#ifndef COMPETITIONGROUPMANAGER_H
#define COMPETITIONGROUPMANAGER_H

#include "competitiongroup.h"

#include <QVector>
#include <QString>

class CompetitionGroupManager {
public:
    CompetitionGroupManager(const QString& filePath);
    void load();

    void save();

    void addGroup(const CompetitionGroup& group);
    void removeGroup(int index);
    QVector<CompetitionGroup> getGroups() const;
    void setGroups(QVector<CompetitionGroup>);

    void removeTeam(const QString& groupLabel, const QString& teamName);

    void removeIndividualParticipant(const QString& groupLabel, const QString& firstName, const QString& lastName);


private:
    QVector<CompetitionGroup> groups;

    QString filePath;
};

#endif // COMPETITIONGROUPMANAGER_H
