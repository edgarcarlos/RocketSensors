#include "sensorwindowvisitor.h"
#include "sensorwindow.h"

SensorWindowVisitor::SensorWindowVisitor(SensorWindow* window) : window(window) {}

void SensorWindowVisitor::visit(Carburante& carburante) {

    window->carburanteInfo(carburante);
}

void SensorWindowVisitor::visit(Pressione& pressione) {
    window->pressionInfo(pressione);
}

void SensorWindowVisitor::visit(Temperatura& temperatura) {
    window->temperatureInfo(temperatura);
}

void SensorWindowVisitor::visit(PositionSensor& positionsensor) {
    window->positionInfo(positionsensor);
}
