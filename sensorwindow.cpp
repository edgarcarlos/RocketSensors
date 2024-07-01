#include "sensorwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

SensorWindow::SensorWindow(AbstractSensor* sensor, QWidget *parent) : SensorWidget(sensor, parent) {

    QVBoxLayout* vbox = new QVBoxLayout();
    QHBoxLayout* hbox = new QHBoxLayout();
    vbox->addLayout(hbox);

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

    QHBoxLayout* hbox2 = new QHBoxLayout();
    vbox-> addLayout(hbox2);

    QVBoxLayout* infoLayout = new QVBoxLayout();
    hbox2->addLayout(infoLayout);




}


void SensorWindow::environmentInfo(const EnvSensor& sensor){

    QWidget* widget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(widget);


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
void SensorWindow::levelInfo(const LevelSensor& sensor){

    QWidget* widget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(widget);


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

    QWidget* widget = new QWidget();
    QVBoxLayout* infoLayout = new QVBoxLayout(widget);


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





















