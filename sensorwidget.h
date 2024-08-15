#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QMouseEvent>

#include "abstractsensor.h"


class SensorWidget : public QWidget {
    Q_OBJECT

public:
    explicit SensorWidget(AbstractSensor* sensor, QWidget *parent = nullptr);
    void setSensorIcon(const QIcon& icon);
    QIcon getSensorIcon() const;
    void setSensorType(const QString& type);
    QString getSensorType() const;
    void setSensorValue(const QString& value);
    void accept(IVisitor& visitor);

protected:
    QString sensorType;
    QIcon sensorIcon;
    void mousePressEvent(QMouseEvent* event) override;

private:
    QWidget* widget;
    AbstractSensor* sensor;
    QLabel* sensorTypeLabel;
    QLabel* sensorIconLabel;
    QLabel* valueLabel;


signals:
    void selected(AbstractSensor* sensor);

};

#endif // SENSORWIDGET_H
