#include "SensorWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <string>

#include "abstractsensor.h"

SensorWidget::SensorWidget(QWidget *parent ): QWidget(parent) {

    QHBoxLayout* hbox = new QHBoxLayout();

    QVBoxLayout* vbox = new QVBoxLayout();
    hbox->addLayout(vbox);

    QHBoxLayout* hbox2 = new QHBoxLayout();
    vbox->addLayout(hbox2);

    QLabel* logo = new QLabel();
    //logo->setPixmap();
    hbox2->addWidget(logo);

    const string nome = "temperatura";
    const string descrizione = "qwertyuiopp";
    const string logo_path = "adfgkernàoes";
    const string ID = "234";
    AbstractSensor Sensor(nome,descrizione,logo_path,ID);
    QLabel* name = new QLabel(QString::fromStdString(Sensor.getName()));
    name->setObjectName("name");
    hbox2->addWidget(name);

    QLabel* type = new QLabel();
    type->setText("type: TEmperature");
    vbox->addWidget(type);


    QLabel* des = new QLabel();
    des->setText("TEmperature mon cul");
    vbox->addWidget(des);

    //QLabel* media = new QLabel()

}


