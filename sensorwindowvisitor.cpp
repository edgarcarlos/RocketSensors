#include "sensorwindowvisitor.h"

SensorWindowVisitor::SensorWindowVisitor(SensorWindow* window) : window(window) {}


void SensorWindowVisitor::visit(Carburante& carburante) {
    window->levelInfo(sensor);
}

void SensorWindowVisitor::visit(Ossigeno& ossigeno) {
    window->levelInfo(sensor);
}

void SensorWindowVisitor::visit(Pressione& pressione) {
    window->environmentInfo(sensor);
}

void SensorWindowVisitor::visit(Temperatura& temperatura) {
    window->environmentInfo(sensor);
}

void SensorWindowVisitor::visit(Umidita& umidita){
    window->environmentInfo(sensor);
}
void SensorWindowVisitor::visit(Velocita& velocita) {

}
void SensorWindowVisitor::visit(Positionsensor& positionsensor) override;
