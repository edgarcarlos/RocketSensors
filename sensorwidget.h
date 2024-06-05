#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include <QString>
#include "abstractsensor.h"

class SensorWidget : public QWidget {
    Q_OBJECT

public:
    explicit SensorWidget(AbstractSensor* sensor, QWidget *parent = nullptr);
    void setSensorIcon(const QString& type);                               type);

private:
    AbstractSensor* sensor;
};

#endif // SENSORWIDGET_H
