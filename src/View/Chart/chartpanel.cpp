#include "chartpanel.h"
#include "../../Sensor/temperatura.h"
#include "../../Sensor/pressione.h"


#include <QVBoxLayout>

namespace View{
namespace Chart{


ChartPanel::ChartPanel(QWidget *parent) : QWidget(parent) {

}

void ChartPanel::envChart(const Sensor::EnvSensor& envSensor){

    clear();
    vector<double> data = envSensor.getDati();

    QLineSeries *series = new QLineSeries();

    for(unsigned int i =0; i < data.size(); ++i){
        series->append(i, data[i]);
    }

    QChart *chart = new QChart();

    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    const Sensor::Temperatura* tempSensor = dynamic_cast<const Sensor::Temperatura*>(&envSensor);
    const Sensor::Pressione* pressSensor = dynamic_cast<const Sensor::Pressione*>(&envSensor);

    if (tempSensor) {
        double min = tempSensor->getTmin();
        double max = tempSensor->getTmax();

        QLineSeries *minLine = new QLineSeries();
        minLine->append(0, min);
        minLine->append(data.size() - 1, min);
        QPen minpen(QColorConstants::Red); // Définir la couleur rouge
        minpen.setStyle(Qt::DashLine);     // Définir le style de ligne en tirets
        minLine->setPen(minpen);

        QLineSeries *maxLine = new QLineSeries();
        maxLine->append(0, max);
        maxLine->append(data.size() - 1, max);
        QPen maxpen(QColorConstants::Red); // Définir la couleur rouge
        maxpen.setStyle(Qt::DashLine);     // Définir le style de ligne en tirets
        maxLine->setPen(maxpen);


        chart->addSeries(minLine);
        chart->addSeries(maxLine);

    } else if (pressSensor) {
        double max = pressSensor->getPmax();

        QLineSeries *maxLine = new QLineSeries();
        maxLine->append(0, max);
        maxLine->append(data.size() - 1, max);
        QPen maxpen(QColorConstants::Red); // Définir la couleur rouge
        maxpen.setStyle(Qt::DashLine);     // Définir le style de ligne en tirets
        maxLine->setPen(maxpen);

        chart->addSeries(maxLine);
    }

    chart->createDefaultAxes();

    chart->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //chartView->setVisible(true);

    if (!layout()) {
        QVBoxLayout *newLayout = new QVBoxLayout();
        setLayout(newLayout);
    }
    layout()->addWidget(chartView);


}



void ChartPanel::levelChart(const Sensor::LevelSensor& levelSensor){
    clear();
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

    if (!layout()) {
        QVBoxLayout *newLayout = new QVBoxLayout();
        setLayout(newLayout);
    }
    layout()->addWidget(chartView);
}




void ChartPanel::positionChart(const Sensor::PositionSensor& positionSensor){
    clear();
    // 1. charts per longitude et la latitude
    QScatterSeries* scatterSeries = new QScatterSeries();
    const vector<Sensor::PositionSensor::Localisation>& locations = positionSensor.getDati();

    for (const auto& location : locations) {
        scatterSeries->append(location.longitude, location.latitude);
    }
    scatterSeries->setMarkerSize(10.0);

    QChart* scatterChart = new QChart();
    scatterChart->addSeries(scatterSeries);
    scatterChart->setTitle("Longitude vs Latitude");
    //scatterChart->createDefaultAxes();

    QValueAxis* axisX = new QValueAxis();
    axisX->setTitleText("Longitude");
    scatterChart->addAxis(axisX, Qt::AlignBottom);  // Replacing setAxisX
    scatterSeries->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setTitleText("Latitude");
    scatterChart->addAxis(axisY, Qt::AlignLeft);  // Replacing setAxisY
    scatterSeries->attachAxis(axisY);

    QChartView* scatterChartView = new QChartView(scatterChart);
    scatterChartView->setRenderHint(QPainter::Antialiasing);
    scatterChartView->setFixedSize(750, 400); // Set fixed size for scatter chart

    // 2. chart per altitude
    QLineSeries* lineSeries = new QLineSeries();

    for (size_t i = 0; i < locations.size(); ++i) {
        lineSeries->append(i, locations[i].altitude);  // Use the index as the x-axis (time) for simplicity
    }

    QChart* lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Altitude Over Time");
    //lineChart->createDefaultAxes();

    QValueAxis* lineAxisX = new QValueAxis();
    lineAxisX->setTitleText("Index"); // Change to a proper time unit if applicable
    lineChart->addAxis(lineAxisX, Qt::AlignBottom);  // Replacing setAxisX
    lineSeries->attachAxis(lineAxisX);

    QValueAxis* lineAxisY = new QValueAxis();
    lineAxisY->setTitleText("Altitude");
    lineChart->addAxis(lineAxisY, Qt::AlignLeft);  // Replacing setAxisY
    lineSeries->attachAxis(lineAxisY);

    QChartView* lineChartView = new QChartView(lineChart);
    lineChartView->setRenderHint(QPainter::Antialiasing);
    lineChartView->setFixedSize(750, 400);
    if (!layout()) {
        QVBoxLayout *newLayout = new QVBoxLayout();
        setLayout(newLayout);
    }
    layout()->addWidget(scatterChartView);
    layout()->addWidget(lineChartView);

}

void ChartPanel::clear() {
    // Clean up any existing charts or widgets
    QLayout* existingLayout = layout();
    if (existingLayout) {
        QLayoutItem* item;
        while ((item = existingLayout->takeAt(0))) {
            // Delete the widget if it exists
            if (item->widget()) {
                delete item->widget();
            }
            // Delete the layout item itself
            delete item;
        }
    }
}

}
}




