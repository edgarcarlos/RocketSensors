QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sensor/abstractsensor.cpp \
    Sensor/carburante.cpp \
    Sensor/envsensor.cpp \
    Sensor/levelsensor.cpp \
    Sensor/positionsensor.cpp \
    Sensor/pressione.cpp \
    Sensor/temperatura.cpp \
    \
    View/mainwindow.cpp \
    View/currentvaluevisitor.cpp \
    View/editwidget.cpp \
    View/searchwidget.cpp \
    View/sensordetails.cpp \
    View/sensorspanel.cpp \
    View/sensorwidget.cpp \
    View/sensordetailsvisitor.cpp \
    View/typeandiconvisitor.cpp\
    \
    View/Chart/chartpanel.cpp \
    View/Chart/chartvisitor.cpp \
    \
    Sensor/Converter/Json/json.cpp \
    Sensor/Converter/Json/jsonvisitor.cpp \
    Sensor/Converter/Json/reader.cpp \
    \
    Sensor/DataMapper/jsonfile.cpp \
    \
    Sensor/Repository/jsonrepository.cpp \
    \
    main.cpp

HEADERS += \
    Sensor/IVisitor.h \
    Sensor/abstractsensor.h \
    Sensor/carburante.h \
    Sensor/envsensor.h \
    Sensor/levelsensor.h \
    Sensor/positionsensor.h \
    Sensor/pressione.h \
    Sensor/sconstvisitor.h \
    Sensor/temperatura.h \
    \
    View/currentvaluevisitor.h \
    View/editwidget.h \
    View/mainwindow.h \
    View/searchwidget.h \
    View/sensordetails.h \
    View/sensordetailsvisitor.h \
    View/sensorspanel.h \
    View/sensorwidget.h \
    View/typeandiconvisitor.h \
    \
    Sensor/Converter/Json/SReader.h \
    Sensor/Converter/Json/json.h \
    Sensor/Converter/Json/jsonvisitor.h \
    Sensor/Converter/Json/reader.h \
    \
    Sensor/DataMapper/jsonfile.h \
    \
    Sensor/Repository/SRepository.h \
    Sensor/Repository/jsonrepository.h \
    \
    View/Chart/chartpanel.h \
    View/Chart/chartvisitor.h


FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    resources.qrc

DISTFILES += \
    styles.qss
