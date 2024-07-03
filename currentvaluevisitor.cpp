#include "currentvaluevisitor.h"

CurrentValueVisitor::CurrentValueVisitor(SensorWidget* widget) : widget(widget) {}


void CurrentValueVisitor::visit(Carburante& carburante) {
    widget->setSensorValue(QString::number(carburante.getCurrentlevel()) + " L");
}
void CurrentValueVisitor::visit(Ossigeno& ossigeno) {
    widget->setSensorValue(QString::number(ossigeno.getCurrentlevel()) + " bar");
}

void CurrentValueVisitor::visit(Pressione& pressione) {
    widget->setSensorValue(QString::number(pressione.getValoreCorrente()) + " Pa");
}
void CurrentValueVisitor::visit(Temperatura& temperatura) {
    widget->setSensorValue(QString::number(temperatura.getValoreCorrente()) + " °C");
}
void CurrentValueVisitor::visit(Umidita& umidita) {
    widget->setSensorValue(QString::number(umidita.getValoreCorrente()) + " %");
}
void CurrentValueVisitor::visit(Velocita& velocita) {
    widget->setSensorValue(QString::number(velocita.velocitaMedia()) + " Km/h");
}
void CurrentValueVisitor::visit(PositionSensor& positionsensor) {
    widget->setSensorValue(QString::number(positionsensor.getAltitude()) + " Km");
}
