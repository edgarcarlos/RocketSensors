#include "typeandiconvisitor.h"

namespace View {

TypeAndIconVisitor::TypeAndIconVisitor(SensorWidget* sensor): sensor(sensor) {}

//attributi comentati per evitare i warnings

void TypeAndIconVisitor::visit(Sensor::Carburante& /*carburante*/) {
    sensor->setSensorType("Carburante");
    sensor->setSensorIcon(QIcon(":Assets/icons/carburante_icon.png"));
}

void TypeAndIconVisitor::visit(Sensor::Pressione& /*pressione*/) {
    sensor->setSensorType("Pressione");
    sensor->setSensorIcon(QIcon(":Assets/icons/pressione_icon.png"));
}

void TypeAndIconVisitor::visit(Sensor::Temperatura& /*temperatura*/) {
    sensor->setSensorType("Temperatura");
    sensor->setSensorIcon(QIcon(":Assets/icons/temperatura_icon.png"));
}

void TypeAndIconVisitor::visit(Sensor::PositionSensor& /*positionsensor*/) {
    sensor->setSensorType("Position");
    sensor->setSensorIcon(QIcon(":Assets/icons/position_icon.png"));
}

}
