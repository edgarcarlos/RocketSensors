#include "sensordetails.h"
#include "sensorDetailsvisitor.h"
#include "typeandiconvisitor.h"
#include "chartvisitor.h"
#include "sensorwidget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

SensorDetails::SensorDetails(AbstractSensor* sensor, QWidget *parent) : QWidget(parent),
                         sensor(sensor)    /*infoLayout(new QVBoxLayout(this))*/ {

    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox = new QHBoxLayout();

    QPushButton* back = new QPushButton(QIcon(QPixmap((":Assets/icons/back_icon.png"))),
                                        "Back");
    hbox->addWidget(back);

    QLabel* name = new QLabel(QString::fromStdString(sensor->getName()));
    name->setObjectName("name");
    hbox->addWidget(name);

    QPushButton* simulate = new QPushButton(QIcon(QPixmap((":Assets/icons/simula_icon.png"))),
                                          "Simulate");
    QPushButton* modify = new QPushButton(QIcon(QPixmap((":Assets/icons/modifica_icon.png"))),
                                            "Modify");
    QPushButton* delete_ = new QPushButton(QIcon(QPixmap((":Assets/icons/delete_icon.png"))),
                                           "Delete");

    int buttonWidth = 100; // Largeur fixe souhaitée pour les boutons

    simulate->setFixedWidth(buttonWidth);
    modify->setFixedWidth(buttonWidth);
    delete_->setFixedWidth(buttonWidth);
    back->setFixedWidth(60);

    hbox->addWidget(simulate);
    hbox->addWidget(modify);
    hbox->addWidget(delete_);

    vbox->addLayout(hbox);

    QHBoxLayout* hbox2 = new QHBoxLayout();

    infoLayout = new QVBoxLayout();
    hbox2->addLayout(infoLayout);

    chartPanel = new ChartPanel();
    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true); // Allows the content to resize automatically
    scrollArea->setWidget(chartPanel); // Set the chart panel as the widget for the scroll area

    hbox2->addWidget(scrollArea);
    vbox-> addLayout(hbox2);

    setLayout(vbox);

    // Connect
    connect(back, &QPushButton::clicked, this, &SensorDetails::handleBack);
    connect(simulate, &QPushButton::clicked, this, &SensorDetails::simulaSensor);
    connect(modify, &QPushButton::clicked, this, &SensorDetails::modifySensor);
    connect(delete_, &QPushButton::clicked, this, &SensorDetails::deleteSensor);

    connect(this, &SensorDetails::simulateSignal, this, &SensorDetails::updateCharts);


    SensorWidget sensorWidget(sensor);
    TypeAndIconVisitor typeAndIconVisitor(&sensorWidget);
    sensor->accept(typeAndIconVisitor);
    sensorType = sensorWidget.getSensorType();

    SensorDetailsVisitor infovisitor(this);
    sensor->accept(infovisitor);

    ChartVisitor chartvisitor(chartPanel);
    sensor->accept(chartvisitor);

}


void SensorDetails::temperatureInfo(const Temperatura& sensor){


    QLabel* sensorTypeLabel = new QLabel("Type: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* current = new QLabel("Current: " + QString::number(sensor.getValoreCorrente()));
    current->setObjectName("current");
    infoLayout->addWidget(current);

    QLabel* min = new QLabel("Min: " + QString::number(sensor.valoreMin()));
    min->setObjectName("min");
    infoLayout->addWidget(min);

    QLabel* max = new QLabel("Max: " + QString::number(sensor.valoreMax()));
    max->setObjectName("max");
    infoLayout->addWidget(max);

    QLabel* average = new QLabel("Average: " + QString::number(sensor.media()));
    average->setObjectName("average");
    infoLayout->addWidget(average);

}

void SensorDetails::pressionInfo(const Pressione& sensor){



    QLabel* sensorTypeLabel = new QLabel("Type: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* current = new QLabel("Current: " + QString::number(sensor.getValoreCorrente()));
    current->setObjectName("current");
    infoLayout->addWidget(current);

    QLabel* min = new QLabel("Min: " + QString::number(sensor.valoreMin()));
    min->setObjectName("min");
    infoLayout->addWidget(min);

    QLabel* max = new QLabel("Max: " + QString::number(sensor.valoreMax()));
    max->setObjectName("max");
    infoLayout->addWidget(max);

    QLabel* average = new QLabel("Average: " + QString::number(sensor.media()));
    average->setObjectName("average");
    infoLayout->addWidget(average);

}
void SensorDetails::carburanteInfo(const Carburante& sensor){

    QLabel* sensorTypeLabel = new QLabel("Type: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* current = new QLabel("Currrent: " + QString::number(sensor.getCurrentlevel()));
    current->setObjectName("current");
    infoLayout->addWidget(current);

    QLabel* capacity = new QLabel("Capacity: " + QString::number(sensor.getCapacity()));
    capacity->setObjectName("capacity");
    infoLayout->addWidget(capacity);


}
void SensorDetails::positionInfo(const PositionSensor& sensor){

    QLabel* sensorTypeLabel = new QLabel("Type: " + sensorType);
    sensorTypeLabel->setObjectName("type");
    infoLayout->addWidget(sensorTypeLabel);

    QLabel* altitude = new QLabel("Altitude: " + QString::number(sensor.getAltitude()));
    altitude->setObjectName("altitude");
    infoLayout->addWidget(altitude);

    QLabel* longitude = new QLabel("Longitude: " + QString::number(sensor.getLongitude()));
    longitude->setObjectName("longitude");
    infoLayout->addWidget(longitude);

    QLabel* latitude = new QLabel("Latitude: " + QString::number(sensor.getLatitude()));
    latitude->setObjectName("latitude");
    infoLayout->addWidget(latitude);



}

void SensorDetails::handleBack() {
    if (stackedWidget) {
        stackedWidget->setCurrentWidget(stackedWidget->widget(0));  // Revenir à searchWidget
    }
}


void SensorDetails::simulaSensor(){
    emit simulateSignal();
}

void SensorDetails::modifySensor(){
    emit modifySignal(sensor);
}

void SensorDetails::deleteSensor(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Sensor",
                                  "Sicuro di cancellare questo sensore?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        emit deleteSignal(sensor);  // Continue with deletion if confirmed
    } else {
        // Do nothing if the user cancels the deletion
    }
}

void SensorDetails::updateCharts() {

    if (auto envSensor = dynamic_cast<EnvSensor*>(sensor)) {
        chartPanel->envChart(*envSensor);
    } else if (auto levelSensor = dynamic_cast<LevelSensor*>(sensor)) {
        chartPanel->levelChart(*levelSensor);
    } else if (auto positionSensor = dynamic_cast<PositionSensor*>(sensor)) {
        chartPanel->positionChart(*positionSensor);
    }
}


void SensorDetails::setStackedWidget(QStackedWidget* stackedWidget) {
    this->stackedWidget = stackedWidget;
}






