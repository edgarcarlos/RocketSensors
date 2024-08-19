#include "typeandiconvisitor.h"

TypeAndIconVisitor::TypeAndIconVisitor(SensorWidget* sensor): sensor(sensor) {}


void TypeAndIconVisitor::visit(Carburante& /*carburante*/) {
    sensor->setSensorType("Carburante");
    sensor->setSensorIcon(QIcon(":Assets/icons/carburante_icon.png"));
}

void TypeAndIconVisitor::visit(Pressione& /*pressione*/) {
    sensor->setSensorType("Pressione");
    sensor->setSensorIcon(QIcon(":Assets/icons/pressione_icon.png"));
}

void TypeAndIconVisitor::visit(Temperatura& /*temperatura*/) {
    sensor->setSensorType("Temperatura");
    sensor->setSensorIcon(QIcon(":Assets/icons/temperatura_icon.png"));
}

void TypeAndIconVisitor::visit(PositionSensor& /*positionsensor*/) {
    sensor->setSensorType("Positionsensor");
    sensor->setSensorIcon(QIcon(":Assets/icons/position_icon.png"));
}

