#ifndef CHARTPANEL_H
#define CHARTPANEL_H

#include <QWidget>

#include "envsensor.h"
#include "levelsensor.h"
#include "positionsensor.h"

#include <QtCharts>

class ChartPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ChartPanel(QWidget *parent = nullptr);
    void envChart(const EnvSensor& envSensor);
    void levelChart(const LevelSensor& levelSensor);
    void positionChart(const PositionSensor& positionSensor);
    void accept(IVisitor& visitor);

};

#endif // CHARTPANEL_H
