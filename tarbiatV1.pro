QT       += core gui
QT += widgets
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    competitiongroupform.cpp \
    competitiongroupmanager.cpp \
    globaldata.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationform.cpp \
    registrationlistform.cpp \
    sortgroups.cpp \
    timetable.cpp \
    timetablesettings.cpp


HEADERS += \
    competitiongroup.h \
    competitiongroupform.h \
    competitiongroupmanager.h \
    globaldata.h \
    mainwindow.h \
    registrationform.h \
    registrationlistform.h \
    sortgroups.h \
    timetable.h \
    timetablesettings.h


FORMS += \
    competitiongroupform.ui \
    mainwindow.ui \
    registrationform.ui \
    registrationlistform.ui \
    sortgroups.ui \
    timetable.ui \
    timetablesettings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    groups.json
