#include "sensordetailsvisitor.h"
#include "sensordetails.h"

SensorDetailsVisitor::SensorDetailsVisitor(SensorDetails* window) : window(window) {}

void SensorDetailsVisitor::visit(Carburante& carburante) {

    window->carburanteInfo(carburante);
}

void SensorDetailsVisitor::visit(Pressione& pressione) {
    window->pressionInfo(pressione);
}

void SensorDetailsVisitor::visit(Temperatura& temperatura) {
    window->temperatureInfo(temperatura);
}

void SensorDetailsVisitor::visit(PositionSensor& positionsensor) {
    window->positionInfo(positionsensor);
}
