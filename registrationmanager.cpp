// #include "registrationmanager.h"
// #include <QFile>
// #include <QUuid>
// #include <QJsonDocument>

// RegistrationManager::RegistrationManager(const QString &filePath)
//     : m_filePath(filePath)
// {
//     load();
// }

// QList<Registration> RegistrationManager::getRegistrations() const
// {
//     return m_registrations;
// }

// void RegistrationManager::addRegistration(const Registration &registration)
// {
//     Registration reg = registration;

//     m_registrations.append(reg);
//     save();
// }



// void RegistrationManager::load()
// {
//     m_registrations.clear();

//     QFile file(m_filePath);
//     if (!file.open(QIODevice::ReadOnly))
//         return;

//     QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
//     file.close();

//     QJsonArray array = doc.object()["registrations"].toArray();
//     for (const QJsonValue &val : array) {
//         m_registrations.append(fromJson(val.toObject()));
//     }
// }

// void RegistrationManager::save() const
// {
//     QJsonArray array;
//     for (const auto &reg : m_registrations) {
//         array.append(toJson(reg));
//     }

//     QJsonObject root;
//     root["registrations"] = array;

//     QFile file(m_filePath);
//     if (!file.open(QIODevice::WriteOnly))
//         return;

//     QJsonDocument doc(root);
//     file.write(doc.toJson());
//     file.close();
// }

// Registration RegistrationManager::fromJson(const QJsonObject &obj)
// {
//     Registration reg;

//     reg.C_Group.matchType = obj["type"].toString()== "Kata" ? MatchType::Kata : MatchType::Kumite;

//     if (reg.type == "individual") {
//         reg.name = obj["name"].toString();
//         reg.gender = obj["gender"].toString();
//     } else if (reg.type == "team") {
//         QJsonArray arr = obj["members"].toArray();
//         for (const auto &v : arr) {
//             QJsonObject m = v.toObject();
//             reg.members.append({ m["name"].toString(), m["gender"].toString() });
//         }
//     }

//     return reg;
// }

// QJsonObject RegistrationManager::toJson(const Registration &reg)
// {
//     QJsonObject obj;


//     obj["type"] = reg.type;

//     if (reg.type == "individual") {
//         obj["name"] = reg.name;
//         obj["gender"] = reg.gender;
//     } else if (reg.type == "team") {
//         QJsonArray arr;
//         for (const auto &m : reg.members) {
//             QJsonObject o;
//             o["name"] = m.name;
//             o["gender"] = m.gender;
//             arr.append(o);
//         }
//         obj["members"] = arr;
//     }

//     return obj;
// }













