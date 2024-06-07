#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include "abstractsensor.h"

class SensorWidget : public QWidget {
    Q_OBJECT

public:
    explicit SensorWidget(AbstractSensor* sensor, QWidget *parent = nullptr);
    void setSensorIcon(const QIcon& icon);
    void setSensorType(const QString& type);

private:
    AbstractSensor* sensor;
    QLabel* sensorTypeLabel;
    QLabel* sensorIcon;
    QString sensorType;
};

#endif // SENSORWIDGET_H
