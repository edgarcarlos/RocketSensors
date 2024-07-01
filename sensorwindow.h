#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include "abstractsensor.h"
#include "sensorwidget.h"
#include "envsensor.h"
#include "levelsensor.h"
#include "positionsensor.h"
#include <QWidget>

class SensorWindow : public SensorWidget
{
    Q_OBJECT

public:
    SensorWindow(AbstractSensor* sensor, QWidget *parent);
    void environmentInfo(const EnvSensor& sensor);
    void levelInfo(const LevelSensor& sensor);
    void positionInfo(const PositionSensor& sensor);

private:

};

#endif // SENSORWINDOW_H
