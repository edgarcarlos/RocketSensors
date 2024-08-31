#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QMouseEvent>
#include <QIcon>

#include "../Sensor/abstractsensor.h"

namespace View {

class SensorWidget : public QWidget {
    Q_OBJECT

public:
    explicit SensorWidget(Sensor::AbstractSensor* sensor, QWidget *parent = nullptr);
    void setSensorIcon(const QIcon& icon);
    QIcon getSensorIcon() const;
    void setSensorType(const QString& type);
    QString getSensorType() const;
    void setSensorValue(const QString& value);
    void accept(Sensor::SVisitor& visitor);

protected:
    QString sensorType;
    QIcon sensorIcon;
    void mousePressEvent(QMouseEvent* event) override;

private:
    Sensor::AbstractSensor* sensor;
    QLabel* sensorTypeLabel;
    QLabel* sensorIconLabel;
    QLabel* valueLabel;

signals:
    void selected(Sensor::AbstractSensor* sensor);

};

}

#endif // SENSORWIDGET_H
