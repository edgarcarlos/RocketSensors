#ifndef SENSORSPANEL_H
#define SENSORSPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <vector>

#include "sensorwidget.h"
#include "../Sensor/abstractSensor.h"
//#include "sensordetails.h"

namespace View {

class SensorsPanel : public QWidget {
    Q_OBJECT

public:
    SensorsPanel(QWidget* parent = nullptr);
    void addSensors(const std::vector<Sensor::AbstractSensor*>& sensors);
    void clearResults();


protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QGridLayout* panelLayout;
    std::vector<SensorWidget*> sensorWidgets;
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
