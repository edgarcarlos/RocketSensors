#include "sensorwindowvisitor.h"
#include "sensorwindow.h"


SensorWindowVisitor::SensorWindowVisitor(QVBoxLayout* layout) : infoLayout(layout) {}


void SensorWindowVisitor::visit(Carburante& carburante) {
    static_cast<SensorWindow*>(infoLayout->parent())->levelInfo(carburante);
}

void SensorWindowVisitor::visit(Ossigeno& ossigeno) {
    static_cast<SensorWindow*>(infoLayout->parent())->levelInfo(ossigeno);
}

void SensorWindowVisitor::visit(Pressione& pressione) {
    static_cast<SensorWindow*>(infoLayout->parent())->environmentInfo(pressione);
}

void SensorWindowVisitor::visit(Temperatura& temperatura) {
    static_cast<SensorWindow*>(infoLayout->parent())->environmentInfo(temperatura);
}

void SensorWindowVisitor::visit(Umidita& umidita) {
    static_cast<SensorWindow*>(infoLayout->parent())->environmentInfo(umidita);
}

void SensorWindowVisitor::visit(Velocita& velocita) {
    static_cast<SensorWindow*>(infoLayout->parent())->positionInfo(velocita);
}

void SensorWindowVisitor::visit(PositionSensor& positionsensor) {
    static_cast<SensorWindow*>(infoLayout->parent())->positionInfo(positionsensor);
}
