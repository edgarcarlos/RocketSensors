#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H

#include "abstractsensor.h"
#include "chartpanel.h"
#include "positionsensor.h"
#include <QWidget>

class SensorWindow : public QWidget
{
    Q_OBJECT

public:
    SensorWindow(AbstractSensor* sensor, QWidget *parent = nullptr);
    void temperatureInfo(const Temperatura& sensor);
    void pressionInfo(const Pressione& sensor);
    void carburanteInfo(const Carburante& sensor);
    void positionInfo(const PositionSensor& sensor);
    void accept(IVisitor& visitor);

private:
    ChartPanel *chartPanel;
    QString sensorType;
    QVBoxLayout* infoLayout;

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
