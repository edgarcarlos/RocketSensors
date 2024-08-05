#include "sensorwindowvisitor.h"

SensorWindowVisitor::SensorWindowVisitor(QVBoxLayout* layout) : infoLayout(layout) {}


void SensorWindowVisitor::visit(Carburante& carburante) {
    infoLayout->levelInfo(carburante);
}

void SensorWindowVisitor::visit(Ossigeno& ossigeno) {
    infoLayout->levelInfo(ossigeno);
}

void SensorWindowVisitor::visit(Pressione& pressione) {
    infoLayout->environmentInfo(pressione);
}

void SensorWindowVisitor::visit(Temperatura& temperatura) {
    infoLayout->environmentInfo(temperatura);
}

void SensorWindowVisitor::visit(Umidita& umidita){
    infoLayout->environmentInfo(umidita);
}
void SensorWindowVisitor::visit(Velocita& velocita) {
    infoLayout->positionInfo(velocita);
}
void SensorWindowVisitor::visit(PositionSensor& positionsensor) {
    infoLayout->positionInfo(positionsensor);

}
