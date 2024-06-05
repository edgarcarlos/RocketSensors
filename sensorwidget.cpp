#include "sensorwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>
#include "abstractsensor.h"

SensorWidget::SensorWidget(AbstractSensor* sensor, QWidget *parent) : QWidget(parent), sensor(sensor) {


    QHBoxLayout* hbox = new QHBoxLayout();
    QVBoxLayout* vbox = new QVBoxLayout();
    hbox->addLayout(vbox);

    QHBoxLayout* hbox2 = new QHBoxLayout();
    vbox->addLayout(hbox2);

    //a rivedere
    //QIcon icon("path/to/icon.png");
    QLabel* sensorIcon = new QLabel();
    //sensorIcon->setIcon(icon);
    //hbox2->addWidget(sensorIcon);

    QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox2->addWidget(name);

    //QLabel* type = new QLabel("Type: " + QString::fromStdString(sensor->getType()));
    //type->setObjectName("type");
    //vbox->addWidget(type);

    QLabel* description = new QLabel(QString::fromStdString(sensor->getDescrizione()));
    description->setObjectName("description");
    vbox->addWidget(description);

    QLabel* ID = new QLabel(QString::fromStdString(sensor->getID()));
    ID->setObjectName("ID");
    vbox->addWidget(ID);

    setLayout(hbox);
}

void SensorWidget::setSensorIcon(const QString& type){

    QIcon icon;

    if (type == "Temperature") {
        icon = QIcon(":/icons/temperature_icon.png");
    } else if (type == "Pressione") {
        icon = QIcon(":/icons/pressure_icon.png");
    } else if (type == "Umidità") {
        icon = QIcon(":/icons/humidity_icon.png");
    } else if (type == "Ossigeno") {
        icon = QIcon(":/icons/light_icon.png");
    } else {

        icon = QIcon(":/icons/default_icon.png");
    }

    sensorIcon->setIcon(icon);

}
