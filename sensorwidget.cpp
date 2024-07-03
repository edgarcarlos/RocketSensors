#include "sensorwidget.h"
//#include "IVisitor.h"
#include "typeandiconvisitor.h"
#include "currentvaluevisitor.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include "abstractsensor.h"

SensorWidget::SensorWidget(AbstractSensor* sensor, QWidget *parent) : QWidget(parent), sensor(sensor) {


    QHBoxLayout* hbox = new QHBoxLayout();
    QVBoxLayout* vbox = new QVBoxLayout();
    hbox->addLayout(vbox);

    QHBoxLayout* hbox2 = new QHBoxLayout();
    vbox->addLayout(hbox2);

    sensorIcon = new QLabel();
    //sensorIcon = new QLabel();
    hbox2->addWidget(sensorIcon);

    QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox2->addWidget(name);

    sensorTypeLabel = new QLabel();
    vbox->addWidget(sensorTypeLabel);


    QLabel* description = new QLabel(QString::fromStdString(sensor->getDescription()));
    description->setObjectName("description");
    vbox->addWidget(description);

    QLabel* ID = new QLabel(QString::fromStdString(sensor->getID()));
    ID->setObjectName("ID");
    vbox->addWidget(ID);

    valueLabel = new QLabel();
    hbox->addWidget(valueLabel);


    TypeAndIconVisitor visitor(this);
    sensor->accept(visitor);

    CurrentValueVisitor valueVisitor(this);
    sensor->accept(valueVisitor);

    setLayout(hbox);
}

void SensorWidget::setSensorIcon(const QIcon& icon){
    sensorIcon->setPixmap(icon.pixmap(32, 32));

}

void SensorWidget::setSensorType(const QString& type){
    sensorType = type;
    sensorTypeLabel->setText(type);
}

void SensorWidget::setSensorValue(const QString& value){
    valueLabel->setText(value);
}
