#include "chartpanel.h"

#include <QVBoxLayout>

ChartPanel::ChartPanel(QWidget *parent) : QWidget(parent) {}


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
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);


}



void ChartPanel::levelChart(const LevelSensor& levelSensor){
    // Calcolo volumi
    qreal usedVolume = levelSensor.getCapacity() - levelSensor.getCurrentlevel();
    qreal remainingVolume = levelSensor.getCurrentlevel();

    // serie di dati
    QPieSeries* series = new QPieSeries();
    series->append("Used Volume", usedVolume);
    series->append("Remaining Volume", remainingVolume);

    // taglia del bucco
    series->setHoleSize(0.5);

    // personnalizazione
    QPieSlice* usedSlice = series->slices().at(0);
    usedSlice->setLabelVisible(true);
    usedSlice->setBrush(Qt::red);
    usedSlice->setLabel(QString("Used Volume: %1").arg(usedVolume));

    QPieSlice* remainingSlice = series->slices().at(1);
    remainingSlice->setLabelVisible(true);
    remainingSlice->setBrush(Qt::green);
    remainingSlice->setLabel(QString("Remaining Volume: %1").arg(remainingVolume));

    // Creazione del grafo
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Level Sensor Volume");


    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
}




void ChartPanel::positionChart(const PositionSensor& positionSensor){
    // 1. charts per longitude et la latitude
    QScatterSeries* scatterSeries = new QScatterSeries();
    const vector<PositionSensor::Localisation>& locations = positionSensor.getDati();

    for (const auto& location : locations) {
        scatterSeries->append(location.longitude, location.latitude);
    }
    scatterSeries->setMarkerSize(10.0);

    QChart* scatterChart = new QChart();
    scatterChart->addSeries(scatterSeries);
    scatterChart->setTitle("Longitude vs Latitude");
    scatterChart->createDefaultAxes();

    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText("Longitude");
    scatterChart->setAxisX(axisX, scatterSeries);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Latitude");
    scatterChart->setAxisY(axisY, scatterSeries);

    QChartView* scatterChartView = new QChartView(scatterChart);
    scatterChartView->setRenderHint(QPainter::Antialiasing);

    // 2. chart per altitude
    QLineSeries* lineSeries = new QLineSeries();

    for (size_t i = 0; i < locations.size(); ++i) {
        lineSeries->append(i, locations[i].altitude);  // Use the index as the x-axis (time) for simplicity
    }

    QChart* lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Altitude Over Time");
    lineChart->createDefaultAxes();

    QValueAxis* lineAxisX = new QValueAxis();
    lineAxisX->setTitleText("Index"); // Change to a proper time unit if applicable
    lineChart->setAxisX(lineAxisX, lineSeries);

    QValueAxis* lineAxisY = new QValueAxis();
    lineAxisY->setTitleText("Altitude");
    lineChart->setAxisY(lineAxisY, lineSeries);

    QChartView* lineChartView = new QChartView(lineChart);
    lineChartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(scatterChartView);
    layout->addWidget(lineChartView);
    setLayout(layout);

}






