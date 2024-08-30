#include "chartvisitor.h"
namespace View{
namespace Chart{

ChartVisitor::ChartVisitor(ChartPanel *chart): chart(chart) {}

void ChartVisitor::visit(Sensor::Carburante& carburante) {
    chart->levelChart(carburante);
}


void ChartVisitor::visit(Sensor::Pressione& pressione) {
    chart->envChart(pressione);
}

void ChartVisitor::visit(Sensor::Temperatura& temperatura) {
    chart->envChart(temperatura);
}


void ChartVisitor::visit(Sensor::PositionSensor& positionsensor) {
    chart->positionChart(positionsensor);
}
}
}
