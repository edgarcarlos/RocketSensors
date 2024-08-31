#ifndef SENSORDETAILS_H
#define SENSORDETAILS_H

#include "../Sensor/abstractsensor.h"
#include "Chart/chartpanel.h"
#include "../Sensor/positionsensor.h"
#include "Chart/chartvisitor.h"

#include <QWidget>

namespace View {

class SensorDetails : public QWidget
{
    Q_OBJECT

public:
    SensorDetails(Sensor::AbstractSensor* sensor, QWidget *parent = nullptr);
    void temperatureInfo(const Sensor::Temperatura& sensor);
    void pressionInfo(const Sensor::Pressione& sensor);
    void carburanteInfo(const Sensor::Carburante& sensor);
    void positionInfo(const Sensor::PositionSensor& sensor);
    void accept(Sensor::SVisitor& visitor);
    void setStackedWidget(QStackedWidget* stackedWidget);


private:
    Sensor::AbstractSensor* sensor;
    Chart::ChartPanel *chartPanel;
    QString sensorType;
    QVBoxLayout* infoLayout;
    QStackedWidget* stackedWidget;

public slots:
    void handleBack();
    void simulaSensor();
    void modifySensor();
    void deleteSensor();
    void updateCharts();

signals:
    void modifySignal(Sensor::AbstractSensor* sensor);
    void simulateSignal();
    void deleteSignal(Sensor::AbstractSensor* sensor);
};
}
#endif // SENSORDETAILS_H
