#include "chartvisitor.h"

ChartVisitor::ChartVisitor(ChartPanel *chart): chart(chart) {}

void ChartVisitor::visit(Carburante& carburante) {
    chart->levelChart(carburante);
}


void ChartVisitor::visit(Pressione& pressione) {
    chart->envChart(pressione);
}

void ChartVisitor::visit(Temperatura& temperatura) {
    chart->envChart(temperatura);
}


void ChartVisitor::visit(PositionSensor& positionsensor) {
    chart->positionChart(positionsensor);
}
