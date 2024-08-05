#include "chartpanel.h"



ChartPanel::ChartPanel() {}


void ChartPanel::envChart(const EnvSensor& envSensor){

    vector<double> data = envSensor.getDati();

    QLineSeries *series = new QLineSeries();

    for(unsigned int i =0; i <= data.size(); ++i){
        series->append(i, data[i]);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 12);
    chart->axes(Qt::Horizontal).first()->setRange(0, 11);
    chart->setVisible(true);

    QChartView *chartView = new QChartView();
    chartView->setRenderHint(Qpainter::Antialiasing);
    chartView->setVisiblle(true);


}



void ChartPanel::levelChart(const LevelSensor& levelSensor);
void ChartPanel::positionChart(const PositionSensor& positionSensor);
