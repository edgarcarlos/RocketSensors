#include "sensorwidget.h"
//#include "svisitor.h"
#include "typeandiconvisitor.h"
#include "currentvaluevisitor.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include "../Sensor/abstractSensor.h"

namespace View {

SensorWidget::SensorWidget(Sensor::AbstractSensor* sensor, QWidget *parent) : QWidget(parent), sensor(sensor) {

    //this->setObjectName("sensorWidget");
    //setStyleSheet("background-color: red; border: 1px solid #000000; border-radius: 5px; padding: 10px;");

    QWidget* widget = new QWidget(this);
    widget->setObjectName("sensorWidget");

    QVBoxLayout* vbox = new QVBoxLayout(this);
    widget->setLayout(vbox);

    vbox->setSpacing(15);
    QHBoxLayout* hbox1 = new QHBoxLayout();
    sensorIconLabel = new QLabel();
    hbox1->addWidget(sensorIconLabel);

    QLabel* name = new QLabel( QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    name->setAlignment(Qt::AlignCenter);
    hbox1->addStretch();
    hbox1->addWidget(name);
    hbox1->addStretch();

    vbox->addLayout(hbox1);

    QVBoxLayout* vbox2 = new QVBoxLayout();

    sensorTypeLabel = new QLabel();
    vbox2->addWidget(sensorTypeLabel);


    QLabel* description = new QLabel("Description: " + QString::fromStdString(sensor->getDescription()));
    description->setWordWrap(true);
    description->setObjectName("description");
    vbox2->addWidget(description);

    QLabel* ID = new QLabel("ID: " + QString::number(sensor->getID()));
    ID->setObjectName("ID");
    vbox2->addWidget(ID);

    vbox->addLayout(vbox2);

    QHBoxLayout* hbox2 = new QHBoxLayout();

    valueLabel = new QLabel();
    valueLabel->setObjectName("valueLabel");
    hbox2->addWidget(valueLabel);

    vbox->addLayout(hbox2);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(widget);
    setLayout(mainLayout);

    TypeAndIconVisitor visitor(this);
    sensor->accept(visitor);

    CurrentValueVisitor valueVisitor(this);
    sensor->accept(valueVisitor);

}

void SensorWidget::setSensorIcon(const QIcon& icon){
    sensorIconLabel->setPixmap(icon.pixmap(32, 32));

}

QIcon SensorWidget::getSensorIcon() const {
    return sensorIcon;
}

void SensorWidget::setSensorType(const QString& type){
    sensorType = type;
    sensorTypeLabel->setText("Type: " + type);
}

QString SensorWidget::getSensorType() const {
    return sensorType;
}


void SensorWidget::setSensorValue(const QString& value){
    valueLabel->setText(value);
}

void SensorWidget::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    // emit quando il widget è cliccato
    emit selected(sensor);
}

}
