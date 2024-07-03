#include "sensorwindowvisitor.h"

SensorWindowVisitor::SensorWindowVisitor(SensorWindow* window) : window(window) {}


void SensorWindowVisitor::visit(Carburante& carburante) {
    window->levelInfo(carburante);
}

void SensorWindowVisitor::visit(Ossigeno& ossigeno) {
    window->levelInfo(ossigeno);
}

void SensorWindowVisitor::visit(Pressione& pressione) {
    window->environmentInfo(pressione);
}

void SensorWindowVisitor::visit(Temperatura& temperatura) {
    window->environmentInfo(temperatura);
}

void SensorWindowVisitor::visit(Umidita& umidita){
    window->environmentInfo(umidita);
}
void SensorWindowVisitor::visit(Velocita& velocita) {
    window->positionInfo(velocita);
}
void SensorWindowVisitor::visit(PositionSensor& positionsensor) {
    window->positionInfo(positionsensor);

}
