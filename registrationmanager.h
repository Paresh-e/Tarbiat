#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <QString>
#include <QList>
#include <QJsonArray>
#include <QJsonObject>
#include "competitiongroup.h"
struct TeamMember {
    QString name;
    QString lastName;
};

struct Registration {
    QString name; // only for individual
    QString lastName;
    CompetitionGroup C_Group;
    QList<TeamMember> members; // only for team
};

// class RegistrationManager
// {
// public:
//     RegistrationManager(const QString &filePath);

//     QList<Registration> getRegistrations() const;
//     void addRegistration(const Registration &registration);


//     void load();
//     void save() const;

// private:
//     QString m_filePath;
//     QList<Registration> m_registrations;

//     static Registration fromJson(const QJsonObject &obj);
//     static QJsonObject toJson(const Registration &reg);


// public :
//     RegistrationManager(const QString &filaPath);






// };

#endif // REGISTRATIONMANAGER_H
