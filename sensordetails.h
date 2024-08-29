#ifndef SENSORDETAILS_H
#define SENSORDETAILS_H

#include "abstractsensor.h"
#include "chartpanel.h"
#include "positionsensor.h"
#include "chartvisitor.h"
#include <QWidget>

class SensorDetails : public QWidget
{
    Q_OBJECT

public:
    SensorDetails(AbstractSensor* sensor, QWidget *parent = nullptr);
    void temperatureInfo(const Temperatura& sensor);
    void pressionInfo(const Pressione& sensor);
    void carburanteInfo(const Carburante& sensor);
    void positionInfo(const PositionSensor& sensor);
    void accept(IVisitor& visitor);
    void setStackedWidget(QStackedWidget* stackedWidget);


private:
    AbstractSensor* sensor;
    ChartPanel *chartPanel;
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
    void modifySignal(AbstractSensor* sensor);
    void simulateSignal();
    void deleteSignal(AbstractSensor* sensor);
    //void backRequested();
};

#endif // SENSORDETAILS_H
