#include "sensorwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include "abstractsensor.h"

SensorWidget::SensorWidget(AbstractSensor* sensor, QWidget *parent) : QWidget(parent), sensor(sensor) {
    QHBoxLayout* hbox = new QHBoxLayout();
    QVBoxLayout* vbox = new QVBoxLayout();
    hbox->addLayout(vbox);

    QHBoxLayout* hbox2 = new QHBoxLayout();
    vbox->addLayout(hbox2);

    //a rivedere
    QPixmap icon("path/to/icon.png");
    QLabel* sensorIcon = new QLabel();
    sensorIcon->setPixmap(icon);
    hbox2->addWidget(sensorIcon);

    QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox2->addWidget(name);

    QLabel* des = new QLabel(QString::fromStdString(sensor->getDescrizione()));
    des->setObjectName("des");
    vbox->addWidget(des);

    QLabel* ID = new QLabel(QString::fromStdString(sensor->getID()));
    ID->setObjectName("ID");
    vbox->addWidget(ID);

    setLayout(hbox);
}
