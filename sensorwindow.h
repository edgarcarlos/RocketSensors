#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include "abstractsensor.h"
#include "sensorwidget.h"
#include "envsensor.h"
#include "levelsensor.h"
#include "positionsensor.h"
#include <QWidget>

class SensorWindow : public QWidget
{
    Q_OBJECT

public:
    SensorWindow(AbstractSensor* sensor, QWidget *parent = nullptr);
    void environmentInfo(const EnvSensor& sensor);
    void levelInfo(const LevelSensor& sensor);
    void positionInfo(const PositionSensor& sensor);

private:

public slots:
    void handleBack();
    void simulaSensor();
    void modifySensor();
    void deleteSensor();

signals:
    void modifySignal();
    void simulateSignal();
    void deleteSignal();
};

#endif // SENSORWINDOW_H
