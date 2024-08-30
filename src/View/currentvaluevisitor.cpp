#include "currentvaluevisitor.h"

namespace View {

CurrentValueVisitor::CurrentValueVisitor(SensorWidget* widget) : widget(widget) {}


void CurrentValueVisitor::visit(Sensor::Carburante& carburante) {
    widget->setSensorValue(QString::number(carburante.getCurrentlevel()) + " L");
}

void CurrentValueVisitor::visit(Sensor::Pressione& pressione) {
    widget->setSensorValue(QString::number(pressione.getValoreCorrente()) + " Pa");
}
void CurrentValueVisitor::visit(Sensor::Temperatura& temperatura) {
    widget->setSensorValue(QString::number(temperatura.getValoreCorrente()) + " °C");
}

void CurrentValueVisitor::visit(Sensor::PositionSensor& positionsensor) {
    widget->setSensorValue(QString::number(positionsensor.getAltitude()) + " Km");
}
}
