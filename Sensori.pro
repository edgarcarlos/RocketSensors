QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractsensor.cpp \
    carburante.cpp \
    chartpanel.cpp \
    chartvisitor.cpp \
    currentvaluevisitor.cpp \
    envsensor.cpp \
    infopanel.cpp \
    levelsensor.cpp \
    listsensor.cpp \
    main.cpp \
    mainwindow.cpp \
    ossigeno.cpp \
    positionsensor.cpp \
    pressione.cpp \
    searchwidget.cpp \
    sensorspanel.cpp \
    sensorwidget.cpp \
    sensorwindow.cpp \
    sensorwindowvisitor.cpp \
    temperatura.cpp \
    typeandiconvisitor.cpp \
    umidita.cpp \
    velocita.cpp

HEADERS += \
    IVisitor.h \
    abstractsensor.h \
    carburante.h \
    chartpanel.h \
    chartvisitor.h \
    currentvaluevisitor.h \
    envsensor.h \
    infopanel.h \
    levelsensor.h \
    listsensor.h \
    mainwindow.h \
    ossigeno.h \
    positionsensor.h \
    pressione.h \
    searchwidget.h \
    sensorspanel.h \
    sensorwidget.h \
    sensorwindow.h \
    sensorwindowvisitor.h \
    temperatura.h \
    typeandiconvisitor.h \
    umidita.h \
    velocita.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
