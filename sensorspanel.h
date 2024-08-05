#ifndef SENSORSPANEL_H
#define SENSORSPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <vector>
#include "sensorwidget.h"
#include "abstractsensor.h"
#include "sensorwindow.h"

using namespace std;

class SensorsPanel : public QWidget {
    Q_OBJECT

public:
    SensorsPanel(QWidget* parent = nullptr);
    void addSensors(const vector<AbstractSensor*>& sensors);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QGridLayout* panelLayout;
    vector<SensorWidget*> sensorWidgets;
    void updateLayout();
    const int initialRowSize = 3;
    QScrollArea* scrollArea;
    QWidget* content;



public slots:
    void showSensor(AbstractSensor* sensor);
};

#endif // SENSORSPANEL_H
