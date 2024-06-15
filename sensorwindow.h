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

private:
    void environmentInfo(EnvSensor* sensor);
    void levelInfo(LevelSensor* sensor);
    void positionInfo(PositionSensor* sensor);
};

#endif // SENSORWINDOW_H
