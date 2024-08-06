#include "chartvisitor.h"

ChartVisitor::ChartVisitor(ChartPanel *chart): chart(chart) {}

void ChartVisitor::visit(Carburante& carburante) {
    chart->levelChart(carburante);
}

void ChartVisitor::visit(Ossigeno& ossigeno) {
    chart->levelChart(ossigeno);
}

void ChartVisitor::visit(Pressione& pressione) {
    chart->envChart(pressione);
}

void ChartVisitor::visit(Temperatura& temperatura) {
    chart->envChart(temperatura);
}

void ChartVisitor::visit(Umidita& umidita) {
    chart->envChart(umidita);
}
void ChartVisitor::visit(Velocita& velocita) {
    chart->positionChart(velocita);
}
void ChartVisitor::visit(PositionSensor& positionsensor) {
    chart->positionChart(positionsensor);
}
