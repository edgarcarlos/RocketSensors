#include "editwidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QLayoutItem>

#include "temperatura.h"
#include "pressione.h"
#include "carburante.h"
#include "positionsensor.h"
#include "typeandiconvisitor.h"

EditWidget::EditWidget(AbstractSensor* sensor,
                       MainWindow* mainWindow,
                       JsonRepository* repository,
                       QWidget* parent)
    : QWidget(parent), mainWindow(mainWindow), sensor(sensor), repository(repository),
    tminLineEdit(nullptr), tmaxLineEdit(nullptr), pmaxLineEdit(nullptr), soglioLineEdit(nullptr), capacityLineEdit(nullptr) {

    qDebug() << "Entering EditWidget constructor.";

    vboxlayout = new QVBoxLayout(this);
    vboxlayout->setObjectName("widget-edit");
    vboxlayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    qDebug() << "QVBoxLayout initialized.";

    idEdit = new QSpinBox();
    idEdit->setObjectName("identifier-input");
    idEdit->setMinimum(1);
    idEdit->setMaximum(INT_MAX);
    vboxlayout->addWidget(idEdit);
    qDebug() << "QSpinBox added.";

    nameEdit = new QLineEdit(this);
    vboxlayout->addWidget(new QLabel("Name:"));
    vboxlayout->addWidget(nameEdit);
    qDebug() << "NameEdit added.";

    descriptionEdit = new QLineEdit(this);
    vboxlayout->addWidget(new QLabel("Description:"));
    vboxlayout->addWidget(descriptionEdit);
    qDebug() << "DescriptionEdit added.";

    typeComboBox = new QComboBox(this);
    typeComboBox->addItem("");
    typeComboBox->addItems({"Temperatura", "Pressione", "Carburante", "Position"});
    vboxlayout->addWidget(new QLabel("Type:"));
    vboxlayout->addWidget(typeComboBox);
    qDebug() << "TypeComboBox added.";

    dynamicFieldsLayout = new QVBoxLayout();
    vboxlayout->addLayout(dynamicFieldsLayout);
    qDebug() << "DynamicFieldsLayout added.";

    connect(typeComboBox, &QComboBox::currentTextChanged, this, &EditWidget::onSensorTypeChanged);
    qDebug() << "TypeComboBox connected.";

    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);
    vboxlayout->addWidget(saveButton);
    vboxlayout->addWidget(cancelButton);
    qDebug() << "Buttons added.";

    setLayout(vboxlayout);
    qDebug() << "Layout set.";

    connect(saveButton, &QPushButton::clicked, this, &EditWidget::apply);
    connect(cancelButton, &QPushButton::clicked, this, &EditWidget::onCancelClicked);
    qDebug() << "Signals connected.";

    // Debug code to check if the sensor is valid and if the subsequent operations are being executed
    qDebug() << "Sensor is" << (sensor ? "valid" : "null");

    if (sensor) {
        SensorWidget sensorWidget(sensor);
        qDebug() << "SensorWidget created.";

        TypeAndIconVisitor typeAndIconVisitor(&sensorWidget);
        qDebug() << "TypeAndIconVisitor created.";

        sensor->accept(typeAndIconVisitor);
        qDebug() << "Sensor accepted visitor.";

        QString sensorType = sensorWidget.getSensorType();
        qDebug() << "Sensor type obtained:" << sensorType;


        idEdit->setValue(sensor->getID());
        idEdit->setEnabled(false);
        nameEdit->setText(QString::fromStdString(sensor->getName()));
        descriptionEdit->setText(QString::fromStdString(sensor->getDescription()));

        typeComboBox->setCurrentText(sensorType);
        onSensorTypeChanged(sensorType);
        typeComboBox->setEnabled(false);
    } else {
        qDebug() << "Sensor is null.";
    }

    qDebug() << "EditWidget constructor completed.";
}

void EditWidget::onSensorTypeChanged(const QString& sensorType) {

    clearDynamicFields();

    if (sensorType == "Temperatura") {
        createTemperatureFields();
    }
    else if (sensorType == "Pressione") {
        createPressionFields();
    }
    else if (sensorType == "Carburante") {
        createCarburanteFields();
    }
    //vboxlayout->update();
    qDebug() << "EditWidget constructor completed.";

}

void EditWidget::clearDynamicFields() {
    // Supprimer tous les widgets dans dynamicFieldsLayout
    QLayoutItem* item;
    while ((item = dynamicFieldsLayout->takeAt(0)) != nullptr) {
        delete item->widget(); // Supprime le widget
        delete item; // Supprime l'item du layout
    }
}

void EditWidget::createTemperatureFields() {
    tminLineEdit = new QLineEdit(this);
    tmaxLineEdit = new QLineEdit(this);

    dynamicFieldsLayout->addWidget(new QLabel("Tmin:"));
    dynamicFieldsLayout->addWidget(tminLineEdit);
    dynamicFieldsLayout->addWidget(new QLabel("Tmax:"));
    dynamicFieldsLayout->addWidget(tmaxLineEdit);

    if (Temperatura *tsensor = dynamic_cast<Temperatura*>(sensor)) {
        // Populate fields with existing sensor data
        tminLineEdit->setText(QString::number(tsensor->getTmin()));
        tmaxLineEdit->setText(QString::number(tsensor->getTmax()));
    }

}

void EditWidget::createPressionFields(){
    pmaxLineEdit = new QLineEdit(this);

    dynamicFieldsLayout->addWidget(new QLabel("Pmax:"));
    dynamicFieldsLayout->addWidget(pmaxLineEdit);

    if(Pressione *psensor = dynamic_cast<Pressione*>(sensor)){
        pmaxLineEdit->setText(QString::number(psensor->getPmax()));

    }
}


void EditWidget::createCarburanteFields(){
    soglioLineEdit = new QLineEdit(this);
    capacityLineEdit = new QLineEdit(this);

    dynamicFieldsLayout->addWidget(new QLabel("Soglio:"));
    dynamicFieldsLayout->addWidget(soglioLineEdit);
    dynamicFieldsLayout->addWidget(new QLabel("Capacity:"));
    dynamicFieldsLayout->addWidget(capacityLineEdit);

    if(Carburante* csensor = dynamic_cast<Carburante*>(sensor)){
        soglioLineEdit->setText(QString::number(csensor->getSoglio()));
    }
    if(LevelSensor* lsensor = dynamic_cast<LevelSensor*>(sensor)){
        capacityLineEdit->setText(QString::number(lsensor->getCapacity()));
    }


}

void EditWidget::apply() {
    qDebug() << "Apply button clicked";

    int ID = idEdit->value();
    QString sensorType = typeComboBox->currentText();
    QString name = nameEdit->text();
    QString description = descriptionEdit->text();


    if (sensor) {
        // Modification d'un capteur existant
        sensor->setName(name.toStdString());
        sensor->setDescription(description.toStdString());

        if (sensorType == "Temperatura") {
            if (auto tempSensor = dynamic_cast<Temperatura*>(sensor)) {
                double tmin = tminLineEdit ? tminLineEdit->text().toDouble() : 0.0;
                double tmax = tmaxLineEdit ? tmaxLineEdit->text().toDouble() : 0.0;
                qDebug() << "Tmin:" << tmin;
                qDebug() << "Tmax:" << tmax;
                tempSensor->setTmin(tmin);
                tempSensor->setTmax(tmax);
            }
        }
        else if (sensorType == "Pressione") {
            if (auto pressSensor = dynamic_cast<Pressione*>(sensor)) {
                double pmax = pmaxLineEdit ? pmaxLineEdit->text().toDouble() : 0.0;
                qDebug() << "Pmax:" << pmax;
                pressSensor->setPmax(pmax);
            }
        }
        else if (sensorType == "Carburante") {
            if (auto carbSensor = dynamic_cast<Carburante*>(sensor)) {
                double soglio = soglioLineEdit ? soglioLineEdit->text().toDouble() : 0.0;
                double capacity = capacityLineEdit ? capacityLineEdit->text().toDouble() : 0.0;
                qDebug() << "Soglio:" << soglio;
                qDebug() << "Capacity:" << capacity;
                carbSensor->setSoglio(soglio);
                carbSensor->setCapacity(capacity);
            }
        }
        // Pour PositionSensor, aucune mise à jour supplémentaire n'est nécessaire car il n'a pas de champs spécifiques dans cet exemple
    } else {
        // Création d'un nouveau capteur
        if (sensorType == "Temperatura") {
            double tmin = tminLineEdit ? tminLineEdit->text().toDouble() : 0.0;
            double tmax = tmaxLineEdit ? tmaxLineEdit->text().toDouble() : 0.0;
            qDebug() << "Tmin:" << tmin;
            qDebug() << "Tmax:" << tmax;
            sensor = new Temperatura(name.toStdString(), description.toStdString(), ID, tmin, tmax);
        }
        else if (sensorType == "Pressione") {
            double pmax = pmaxLineEdit ? pmaxLineEdit->text().toDouble() : 0.0;
            qDebug() << "Pmax:" << pmax;
            sensor = new Pressione(name.toStdString(), description.toStdString(), ID, pmax);
        }
        else if (sensorType == "Carburante") {
            double soglio = soglioLineEdit ? soglioLineEdit->text().toDouble() : 0.0;
            double capacity = capacityLineEdit ? capacityLineEdit->text().toDouble() : 0.0;
            qDebug() << "Soglio:" << soglio;
            qDebug() << "Capacity:" << capacity;
            sensor = new Carburante(name.toStdString(), description.toStdString(), ID, capacity, soglio);
        }
        else if (sensorType == "Position") {
            sensor = new PositionSensor(name.toStdString(), description.toStdString(), ID);
        }
    }

    if (sensor) {
        JsonRepository* repo = mainWindow->getRepository();
        if (repo) {
            qDebug() << "Repository available, updating sensor.";
            repo->update(sensor);
            emit sensorSaved();
        } else {
            qDebug() << "Repository not available.";
        }
    }}

void EditWidget::onCancelClicked() {
    emit editCanceled();
}

AbstractSensor* EditWidget::getSensor() const { return sensor; }







