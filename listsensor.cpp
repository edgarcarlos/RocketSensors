#include "listsensor.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPushButton>

#include "abstractsensor.h"


ListSensor::ListSensor() {}


void ListSensor:: visit(const AbstractSensor& sensor) {

    widget = new QWidget();

    QHBoxLayout* hbox = new QHBoxLayout(widget);

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    hbox->addLayout(vbox);

    QPixmap iconSensor(sensor.getLogo().c_str());
    iconSensor = QPixmap(":/Assets/858753.png");

    QLabel* icon = new QLabel();
    icon ->setPixmap(iconSensor);
    vbox -> addWidget(icon);

    QLabel* name = new QLabel(QString::fromStdString(sensor.getName()));
    name->setObjectName("name");
    vbox->addWidget(name);

    QLabel* descrizione = new QLabel(QString::fromStdString(sensor.getDescrizione()));
    descrizione->setObjectName("descrizione");
    vbox->addWidget(descrizione);

    QLabel* ID = new QLabel(QString::fromStdString(sensor.getID()));
    ID ->setObjectName("ID");
    vbox->addWidget(ID);



    


}
