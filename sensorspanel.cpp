#include "sensorspanel.h"

#include <QGridLayout>

SensorsPanel::SensorsPanel(Qwidget* parent): Qwidget(parent) {

    QGridLayout* panelLayout = new QGridLayout(this);
    panelLayout->setAlignment(Qt::AlignTop);

    setLayout(panelLayout);


}


void SensorsPanel::addSensor(AbstractSensor* sensor){

}
