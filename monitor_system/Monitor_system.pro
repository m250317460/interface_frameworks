#-------------------------------------------------
#
# Project created by QtCreator 2022-02-09T15:23:23
#
#-------------------------------------------------

QT       += core gui
QT       += charts
#QT       += qaxcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Monitor_system
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    textticker.cpp \
    production_management.cpp \
    monitor.cpp \
    pro_plan.cpp \
    pro_update.cpp \
    pro_real.cpp \
    tz_status.cpp \
    data_center.cpp \
    tem_show.cpp \
    construction_plan.cpp \
    innovation.cpp \
    safety_rules.cpp \
    safety_logs.cpp \
    signup.cpp \
    logs.cpp \
    pro_logs.cpp \
    pro_table.cpp \
    mycheckbox.cpp \
    temp_2.cpp


HEADERS += \
        mainwindow.h \
    textticker.h \
    production_management.h \
    monitor.h \
    pro_plan.h \
    pro_update.h \
    pro_real.h \
    tz_status.h \
    tem_show.h \
    data_center.h \
    construction_plan.h \
    innovation.h \
    safety_rules.h \
    safety_logs.h \
    signup.h \
    logs.h \
    pro_logs.h \
    pro_table.h \
    mycheckbox.h \
    temp_2.h

FORMS += \
        mainwindow.ui \
    production_management.ui \
    monitor.ui \
    pro_plan.ui \
    pro_update.ui \
    pro_real.ui \
    tz_status.ui \
    tem_show.ui \
    data_center.ui \
    construction_plan.ui \
    innovation.ui \
    safety_rules.ui \
    safety_logs.ui \
    signup.ui \
    logs.ui \
    pro_logs.ui \
    pro_table.ui \
    temp.ui \
    temp_2.ui


RESOURCES += \
    qdarkstyle/dark/style.qrc \
    qdarkstyle/light/style.qrc
#RESOURCES += qdarkstyle/light/style.qrc




include(qtxlsx/src/xlsx/qtxlsx.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    test.txt
