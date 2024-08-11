#include "typeandiconvisitor.h"

TypeAndIconVisitor::TypeAndIconVisitor(SensorWidget* sensor): sensor(sensor) {}


void TypeAndIconVisitor::visit(Carburante& /*carburante*/) {
    sensor->setSensorType("Carburante");
    sensor->setSensorIcon(QIcon(":/icons/carburante_icon.png"));
}

void TypeAndIconVisitor::visit(Pressione& /*pressione*/) {
    sensor->setSensorType("Pressione");
    sensor->setSensorIcon(QIcon(":/icons/pressione_icon.png"));
}

void TypeAndIconVisitor::visit(Temperatura& /*temperatura*/) {
    sensor->setSensorType("Temperatura");
    sensor->setSensorIcon(QIcon(":/icons/temperatura_icon.png"));
}

void TypeAndIconVisitor::visit(PositionSensor& /*positionsensor*/) {
    sensor->setSensorType("positionsensor");
    sensor->setSensorIcon(QIcon(":/icons/positionsensor.png"));
}

