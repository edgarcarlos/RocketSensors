#ifndef SENSORSPANEL_H
#define SENSORSPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <vector>
#include "sensorwidget.h"
#include "../Sensor/abstractSensor.h"
#include "sensordetails.h"


using namespace std;

namespace View {

class SensorsPanel : public QWidget {
    Q_OBJECT

public:
    SensorsPanel(QWidget* parent = nullptr);
    void addSensors(const vector<Sensor::AbstractSensor*>& sensors);
    void clearResults();


protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QGridLayout* panelLayout;
    vector<SensorWidget*> sensorWidgets;
    void updateLayout();
    const int initialRowSize = 3;
    QScrollArea* scrollArea;
    QWidget* content;

signals:
    void sensorClicked(Sensor::AbstractSensor* sensor);

public slots:
    void showSensor(Sensor::AbstractSensor* sensor);
};
}
#endif // SENSORSPANEL_H
