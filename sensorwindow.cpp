#include "sensorwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

SensorWindow::SensorWindow(AbstractSensor* sensor, QWidget *parent) : QWidget(parent), sensor(sensor) {

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

   /* QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox->addWidget(name);

    QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox->addWidget(name);

    QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox->addWidget(name);*/


}
