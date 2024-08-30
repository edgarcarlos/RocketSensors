#ifndef CHARTPANEL_H
#define CHARTPANEL_H

#include <QWidget>

#include "../../Sensor/envsensor.h"
#include "../../Sensor/levelsensor.h"
#include "../../Sensor/positionsensor.h"

#include <QtCharts>

namespace View{
namespace Chart{

class ChartPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ChartPanel(QWidget *parent = nullptr);
    void envChart(const Sensor::EnvSensor& envSensor);
    void levelChart(const Sensor::LevelSensor& levelSensor);
    void positionChart(const Sensor::PositionSensor& positionSensor);
    void accept(Sensor::IVisitor& visitor);
    void clear();

private:
    QVBoxLayout* mainLayout;


};
}
}
#endif // CHARTPANEL_H
