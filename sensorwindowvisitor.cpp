#include "sensorwindowvisitor.h"
#include "sensorwindow.h"


SensorWindowVisitor::SensorWindowVisitor(QVBoxLayout* layout) : infoLayout(layout) {}


void SensorWindowVisitor::visit(Carburante& carburante) {
    static_cast<SensorWindow*>(infoLayout->parent())->levelInfo(carburante);
}


void SensorWindowVisitor::visit(Pressione& pressione) {
    static_cast<SensorWindow*>(infoLayout->parent())->environmentInfo(pressione);
}

void SensorWindowVisitor::visit(Temperatura& temperatura) {
    static_cast<SensorWindow*>(infoLayout->parent())->environmentInfo(temperatura);
}


void SensorWindowVisitor::visit(PositionSensor& positionsensor) {
    static_cast<SensorWindow*>(infoLayout->parent())->positionInfo(positionsensor);
}
