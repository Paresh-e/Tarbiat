#include "competitiongroupmanager.h"
#
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

CompetitionGroupManager::CompetitionGroupManager(const QString& path)
    : filePath(path) {

}
void CompetitionGroupManager::setGroups(QVector<CompetitionGroup> c){
    groups.clear();
    for(int i = 0 ; i<c.size();i++){

        groups.push_back(c[i]);
    }
    save();
}
void CompetitionGroupManager::load() {
    groups.clear();

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file for reading:" << filePath;
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qWarning() << "Invalid JSON format in file";
        return;
    }

    QJsonArray groupArray = doc.array();
    for (const QJsonValue& groupVal : groupArray) {
        if (!groupVal.isObject()) continue;

        QJsonObject groupObj = groupVal.toObject();
        CompetitionGroup group;

        group.ageCategory = groupObj["ageCategory"].toString();
        group.weightCategory = groupObj["weightCategory"].toString();
        QString genderStr = groupObj["gender"].toString();
        group.gender = genderStr == "Male" ? Gender::Male : Gender::Female;
        group.matchDuration = groupObj["matchDuration"].toDouble();

        QString matchTypeStr = groupObj["matchType"].toString();
        if (matchTypeStr == "Kata")
            group.matchType = MatchType::Kata;
        else if (matchTypeStr == "Kumite")
            group.matchType = MatchType::Kumite;


        QString entryStr = groupObj["entryType"].toString();
        group.entryType = (entryStr == "Team") ? EntryType::Team : EntryType::Individual;

        group.teamSize = groupObj["teamSize"].toInt();

        if (group.entryType == EntryType::Individual) {
            QJsonArray participantsArray = groupObj["participants"].toArray();
            for (const QJsonValue& pVal : participantsArray) {
                QJsonObject pObj = pVal.toObject();
                Participant p;
                p.firstName = pObj["firstName"].toString();
                p.lastName = pObj["lastName"].toString();
                group.participants.append(p);
            }
        } else { // Team
            QJsonArray teamsArray = groupObj["teams"].toArray();
            for (const QJsonValue& tVal : teamsArray) {
                QJsonObject tObj = tVal.toObject();
                Team team;
                team.teamName = tObj["teamName"].toString();

                QJsonArray membersArray = tObj["members"].toArray();
                for (const QJsonValue& mVal : membersArray) {
                    QJsonObject mObj = mVal.toObject();
                    Participant m;
                    m.firstName = mObj["firstName"].toString();
                    m.lastName = mObj["lastName"].toString();
                    team.members.append(m);
                }

                group.teams.append(team);
            }
        }

        groups.append(group);
    }
}



void CompetitionGroupManager::addGroup(const CompetitionGroup& group) {
    groups.append(group);
    save();
}

void CompetitionGroupManager::removeGroup(int index) {
    if (index >= 0 && index < groups.size()){

        groups.removeAt(index);
        save();
    }
}

QVector<CompetitionGroup> CompetitionGroupManager::getGroups() const {

    return groups;
}
QJsonObject CompetitionGroup::toJson() const{
    QJsonObject obj;
    obj["ageCategory"] = ageCategory;
    obj["weightCategory"] = weightCategory;
    obj["gender"] = gender==Gender::Male ? "Male" : "Female";
    obj["matchType"] = matchType== MatchType::Kata ? "Kata": "Kumite";
    obj["entryType"] = entryType == EntryType::Team ? "Team" : "Individual";
    obj["teamSize"] = teamSize;
    obj["matchDuration"] = matchDuration;
    if (entryType == EntryType::Individual) {
        QJsonArray participantsArray;
        for (const Participant& p : participants) {
            QJsonObject pObj;
            pObj["firstName"] = p.firstName;
            pObj["lastName"] = p.lastName;
            participantsArray.append(pObj);
        }
        obj["participants"] = participantsArray;
    } else {

        QJsonArray teamsArray;
        for (const Team& t : teams) {
            QJsonObject tObj;
            tObj["teamName"] = t.teamName;
            QJsonArray membersArray;
            for (const Participant& m : t.members) {
                QJsonObject mObj;
                mObj["firstName"] = m.firstName;
                mObj["lastName"] = m.lastName;

                membersArray.append(mObj);
            }
            tObj["members"] = membersArray;
            teamsArray.append(tObj);
        }
        obj["teams"] = teamsArray;
    }



    return obj;
}
void CompetitionGroupManager::save() {
    QJsonArray groupArray;
    for (const CompetitionGroup& g : groups) {
        groupArray.append(g.toJson());
    }

    QJsonDocument doc(groupArray);
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }else{

    }
}




bool compareLabel(const QString& label, const CompetitionGroup& group) {
    QString groupLabel = QString("Group - Age: %1 | Weight: %2 | Gender: %3 | MatchType: %4 | MatchDuration: %5")
    .arg(group.ageCategory)
        .arg(group.weightCategory)
        .arg(group.gender == Gender::Male ? "Male" : "Female")
        .arg(group.matchType == MatchType::Kata ? "Kata" : "Kumite")
        .arg(group.matchDuration);
    return label == groupLabel;
}

void CompetitionGroupManager::removeTeam(const QString& groupLabel, const QString& teamName)
{
    for (CompetitionGroup& group : groups) {
        if (compareLabel(groupLabel, group)) {
            group.teams.erase(std::remove_if(group.teams.begin(), group.teams.end(),
                                             [&](const Team& t) { return t.teamName == teamName; }), group.teams.end());
            return;
        }
    }
    save();
}



void CompetitionGroupManager::removeIndividualParticipant(const QString& groupLabel, const QString& firstName, const QString& lastName)
{
    for (CompetitionGroup& group : groups) {
        if (compareLabel(groupLabel, group)) {
            group.participants.erase(std::remove_if(group.participants.begin(), group.participants.end(),
                                                    [&](const Participant& p) {
                                                        return p.firstName == firstName && p.lastName == lastName;
                                                    }), group.participants.end());
            return;
        }
    }
    save();
}




