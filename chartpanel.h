#ifndef CHARTPANEL_H
#define CHARTPANEL_H

#include "envsensor.h"
#include "levelsensor.h"
#include "positionsensor.h"

#include <QtCharts>

class ChartPanel
{
public:
    ChartPanel();
    void envChart(const EnvSensor& envSensor);
    void levelChart(const LevelSensor& levelSensor);
    void positionChart(const PositionSensor& positionSensor);

};

#endif // CHARTPANEL_H
