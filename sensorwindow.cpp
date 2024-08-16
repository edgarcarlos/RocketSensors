#include "sensorwindow.h"
#include "sensorwindowvisitor.h"
#include "typeandiconvisitor.h"
#include "chartvisitor.h"
#include "sensorwidget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

SensorWindow::SensorWindow(AbstractSensor* sensor, QWidget *parent) : QWidget(parent),
                            infoLayout(new QVBoxLayout(this)) {

    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox = new QHBoxLayout();

    QPushButton* back = new QPushButton();
    hbox->addWidget(back);

    QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox->addWidget(name);

    QPushButton* simula = new QPushButton();
    QPushButton* modifica = new QPushButton();
    QPushButton* delete_ = new QPushButton();

    hbox->addWidget(simula);
    hbox->addWidget(modifica);
    hbox->addWidget(delete_);

    vbox->addLayout(hbox);

    QHBoxLayout* hbox2 = new QHBoxLayout();

    hbox2->addLayout(infoLayout);

    chartPanel = new ChartPanel();
    hbox2->addWidget(chartPanel);
    vbox-> addLayout(hbox2);

    setLayout(vbox);

    // Connect
    connect(back, &QPushButton::clicked, this, &SensorWindow::handleBack);
    connect(simula, &QPushButton::clicked, this, &SensorWindow::simulaSensor);
    connect(modifica, &QPushButton::clicked, this, &SensorWindow::modifySensor);
    connect(delete_, &QPushButton::clicked, this, &SensorWindow::deleteSensor);


    SensorWidget sensorWidget(sensor);
    TypeAndIconVisitor typeAndIconVisitor(&sensorWidget);
    sensor->accept(typeAndIconVisitor);
    sensorType = sensorWidget.getSensorType();

    SensorWindowVisitor infovisitor(this);
    sensor->accept(infovisitor);

    ChartVisitor chartvisitor(chartPanel);
    sensor->accept(chartvisitor);

}


void SensorWindow::temperatureInfo(const Temperatura& sensor){


    QLabel* sensorTypeLabel = new QLabel("Tipo: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* current = new QLabel("Attuale" + QString::number(sensor.getValoreCorrente()));
    current->setObjectName("current");
    infoLayout->addWidget(current);

    QLabel* min = new QLabel("Min" + QString::number(sensor.valoreMin()));
    min->setObjectName("min");
    infoLayout->addWidget(min);

    QLabel* max = new QLabel("Max" + QString::number(sensor.valoreMax()));
    max->setObjectName("max");
    infoLayout->addWidget(max);

    QLabel* average = new QLabel("Media" + QString::number(sensor.media()));
    average->setObjectName("average");
    infoLayout->addWidget(average);

}

void SensorWindow::pressionInfo(const Pressione& sensor){



    QLabel* sensorTypeLabel = new QLabel("Tipo: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* current = new QLabel("Attuale" + QString::number(sensor.getValoreCorrente()));
    current->setObjectName("current");
    infoLayout->addWidget(current);

    QLabel* min = new QLabel("Min" + QString::number(sensor.valoreMin()));
    min->setObjectName("min");
    infoLayout->addWidget(min);

    QLabel* max = new QLabel("Max" + QString::number(sensor.valoreMax()));
    max->setObjectName("max");
    infoLayout->addWidget(max);

    QLabel* average = new QLabel("Media" + QString::number(sensor.media()));
    average->setObjectName("average");
    infoLayout->addWidget(average);

}
void SensorWindow::carburanteInfo(const Carburante& sensor){

    QLabel* sensorTypeLabel = new QLabel("Tipo: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* current = new QLabel("Attuale: " + QString::number(sensor.getCurrentlevel()));
    current->setObjectName("current");
    infoLayout->addWidget(current);

    QLabel* capacity = new QLabel("Capacità: " + QString::number(sensor.getCapacity()));
    capacity->setObjectName("capacity");
    infoLayout->addWidget(capacity);


}
void SensorWindow::positionInfo(const PositionSensor& sensor){

    QLabel* sensorTypeLabel = new QLabel("Tipo: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* altitude = new QLabel("Altitude: " + QString::number(sensor.getAltitude()));
    altitude->setObjectName("altitude");
    infoLayout->addWidget(altitude);

    QLabel* longitude = new QLabel("Min" + QString::number(sensor.getLongitude()));
    longitude->setObjectName("longitude");
    infoLayout->addWidget(longitude);

    QLabel* latitude = new QLabel("Max" + QString::number(sensor.getLatitude()));
    latitude->setObjectName("latitude");
    infoLayout->addWidget(latitude);



}

void SensorWindow::handleBack(){
    close();
}

void SensorWindow::simulaSensor(){
    emit simulateSignal();
}

void SensorWindow::modifySensor(){
    emit modifySignal();
}

void SensorWindow::deleteSensor(){
    emit deleteSignal();
}


















