#include "sensordetailsvisitor.h"
#include "sensordetails.h"

namespace View {

SensorDetailsVisitor::SensorDetailsVisitor(SensorDetails* window) : window(window) {}

void SensorDetailsVisitor::visit(Sensor::Carburante& carburante) {

    window->carburanteInfo(carburante);
}

void SensorDetailsVisitor::visit(Sensor::Pressione& pressione) {
    window->pressionInfo(pressione);
}

void SensorDetailsVisitor::visit(Sensor::Temperatura& temperatura) {
    window->temperatureInfo(temperatura);
}

void SensorDetailsVisitor::visit(Sensor::PositionSensor& positionsensor) {
    window->positionInfo(positionsensor);
}

}
