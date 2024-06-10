#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include "abstractsensor.h"
#include "sensorwidget.h"
#include <QWidget>

class SensorWindow
{
public:
    SensorWindow(AbstractSensor* sensor, QWidget *parent);
};

#endif // SENSORWINDOW_H
