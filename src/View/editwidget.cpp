#include "editwidget.h"
#include "../Sensor/temperatura.h"
#include "../Sensor/pressione.h"
#include "../Sensor/carburante.h"
#include "../Sensor/positionsensor.h"
#include "typeandiconvisitor.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QLayoutItem>
#include <QMessageBox>

namespace View {

EditWidget::EditWidget(Sensor::AbstractSensor* sensor,
                       MainWindow* mainWindow,
                       Sensor::Repository::JsonRepository* repository,
                       QWidget* parent)
    : QWidget(parent), mainWindow(mainWindow), sensor(sensor), repository(repository),
    tminLineEdit(nullptr), tmaxLineEdit(nullptr), pmaxLineEdit(nullptr), sogliaLineEdit(nullptr), capacityLineEdit(nullptr) {


    vboxlayout = new QVBoxLayout(this);
    vboxlayout->setObjectName("widget-edit");
    vboxlayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    //ID edit
    idEdit = new QSpinBox();
    idEdit->setObjectName("identifier-input");
    idEdit->setMinimum(1);
    idEdit->setMaximum(INT_MAX);
    vboxlayout->addWidget(idEdit);

    //name edit
    nameEdit = new QLineEdit(this);
    vboxlayout->addWidget(new QLabel("Name:"));
    vboxlayout->addWidget(nameEdit);

    //description edit
    descriptionEdit = new QLineEdit(this);
    vboxlayout->addWidget(new QLabel("Description:"));
    vboxlayout->addWidget(descriptionEdit);

    //tipi a scelta
    typeComboBox = new QComboBox(this);
    typeComboBox->addItem("");
    typeComboBox->addItems({"Temperatura", "Pressione", "Carburante", "Position"});
    vboxlayout->addWidget(new QLabel("Type:"));
    vboxlayout->addWidget(typeComboBox);
    qDebug() << "TypeComboBox added.";

    //creazione di layout dinamico che cambia a seconda del tipo di sensore
    dynamicFieldsLayout = new QVBoxLayout();
    vboxlayout->addLayout(dynamicFieldsLayout);
    qDebug() << "DynamicFieldsLayout added.";

    connect(typeComboBox, &QComboBox::currentTextChanged, this, &EditWidget::onSensorTypeChanged);

    //pulsante save e cancel
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);
    vboxlayout->addWidget(saveButton);
    vboxlayout->addWidget(cancelButton);

    setLayout(vboxlayout);

    connect(saveButton, &QPushButton::clicked, this, &EditWidget::apply);
    connect(cancelButton, &QPushButton::clicked, this, &EditWidget::onCancelClicked);

    connect(nameEdit, &QLineEdit::textChanged, this, &EditWidget::checkForChanges);
    connect(descriptionEdit, &QLineEdit::textChanged, this, &EditWidget::checkForChanges);
    connect(idEdit, QOverload<int>::of(&QSpinBox::valueChanged), this, &EditWidget::checkForChanges);


    //caso in cui esiste già un sensore da edit (caso di modifica )
    if (sensor) {
        SensorWidget sensorWidget(sensor);
        TypeAndIconVisitor typeAndIconVisitor(&sensorWidget);
        sensor->accept(typeAndIconVisitor);
        QString sensorType = sensorWidget.getSensorType();

        // fare i set dei dati nei campi
        idEdit->setValue(sensor->getID());
        idEdit->setEnabled(false);
        nameEdit->setText(QString::fromStdString(sensor->getName()));
        descriptionEdit->setText(QString::fromStdString(sensor->getDescription()));

        typeComboBox->setCurrentText(sensorType);
        onSensorTypeChanged(sensorType);
        typeComboBox->setEnabled(false);

    }

    if (tminLineEdit) connect(tminLineEdit, &QLineEdit::textChanged, this, &EditWidget::checkForChanges);
    if (tmaxLineEdit) connect(tmaxLineEdit, &QLineEdit::textChanged, this, &EditWidget::checkForChanges);
    if (pmaxLineEdit) connect(pmaxLineEdit, &QLineEdit::textChanged, this, &EditWidget::checkForChanges);
    if (sogliaLineEdit) connect(sogliaLineEdit, &QLineEdit::textChanged, this, &EditWidget::checkForChanges);
    if (capacityLineEdit) connect(capacityLineEdit, &QLineEdit::textChanged, this, &EditWidget::checkForChanges);


    storeInitialValues();
    saveButton->setEnabled(false);
}

void EditWidget::storeInitialValues() {

    //ottenere i dati per verificare se sono cambiati prima del save
    initialName = nameEdit->text();
    initialDescription = descriptionEdit->text();
    initialID = idEdit->value();
    if (tminLineEdit) initialTmin = tminLineEdit->text().toDouble();
    if (tmaxLineEdit) initialTmax = tmaxLineEdit->text().toDouble();
    if (pmaxLineEdit) initialPmax = pmaxLineEdit->text().toDouble();
    if (sogliaLineEdit) initialSoglia = sogliaLineEdit->text().toDouble();
    if (capacityLineEdit) initialCapacity = capacityLineEdit->text().toDouble();

}

void EditWidget::checkForChanges() {

    //verifica se c'è cambiamento
    bool isModified = false;

    if (nameEdit->text() != initialName) isModified = true;
    if (descriptionEdit->text() != initialDescription) isModified = true;
    if (idEdit->value() != initialID) isModified = true;

    if (tminLineEdit && tminLineEdit->text().toDouble() != initialTmin) isModified = true;
    if (tmaxLineEdit && tmaxLineEdit->text().toDouble() != initialTmax) isModified = true;
    if (pmaxLineEdit && pmaxLineEdit->text().toDouble() != initialPmax) isModified = true;
    if (sogliaLineEdit && sogliaLineEdit->text().toDouble() != initialSoglia) isModified = true;
    if (capacityLineEdit && capacityLineEdit->text().toDouble() != initialCapacity) isModified = true;


    saveButton->setEnabled(isModified);  // Attivare oppure disattivare il pulsante "Save"
}


void EditWidget::onSensorTypeChanged(const QString& sensorType) {

    clearDynamicFields();

    //aggiunto dei campi dinamici
    if (sensorType == "Temperatura") {
        createTemperatureFields();
    }
    else if (sensorType == "Pressione") {
        createPressionFields();
    }
    else if (sensorType == "Carburante") {
        createCarburanteFields();
    }

}

void EditWidget::clearDynamicFields() {

    QLayoutItem* item;
    while ((item = dynamicFieldsLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

void EditWidget::createTemperatureFields() {
    tminLineEdit = new QLineEdit(this);
    tmaxLineEdit = new QLineEdit(this);

    dynamicFieldsLayout->addWidget(new QLabel("Tmin:"));
    dynamicFieldsLayout->addWidget(tminLineEdit);
    dynamicFieldsLayout->addWidget(new QLabel("Tmax:"));
    dynamicFieldsLayout->addWidget(tmaxLineEdit);

    if (Sensor::Temperatura *tsensor = dynamic_cast<Sensor::Temperatura*>(sensor)) {
        // Popolare i campi con dati esistenti
        tminLineEdit->setText(QString::number(tsensor->getTmin()));
        tmaxLineEdit->setText(QString::number(tsensor->getTmax()));
    }

}

void EditWidget::createPressionFields(){
    pmaxLineEdit = new QLineEdit(this);

    dynamicFieldsLayout->addWidget(new QLabel("Pmax:"));
    dynamicFieldsLayout->addWidget(pmaxLineEdit);

    if(Sensor::Pressione *psensor = dynamic_cast<Sensor::Pressione*>(sensor)){
        // Popolare i campi con dati esistenti
        pmaxLineEdit->setText(QString::number(psensor->getPmax()));

    }
}


void EditWidget::createCarburanteFields(){
    sogliaLineEdit = new QLineEdit(this);
    capacityLineEdit = new QLineEdit(this);

    dynamicFieldsLayout->addWidget(new QLabel("Soglia:"));
    dynamicFieldsLayout->addWidget(sogliaLineEdit);
    dynamicFieldsLayout->addWidget(new QLabel("Capacity:"));
    dynamicFieldsLayout->addWidget(capacityLineEdit);

    // Popolare i campi con dati esistenti
    if(Sensor::Carburante* csensor = dynamic_cast<Sensor::Carburante*>(sensor)){
        sogliaLineEdit->setText(QString::number(csensor->getSoglia()));
    }
    if(Sensor::LevelSensor* lsensor = dynamic_cast<Sensor::LevelSensor*>(sensor)){
        capacityLineEdit->setText(QString::number(lsensor->getCapacity()));
    }


}

void EditWidget::apply() {

    unsigned int ID = idEdit->value();
    QString sensorType = typeComboBox->currentText();
    QString name = nameEdit->text();
    QString description = descriptionEdit->text();

    if (repository->read(ID) && (!sensor || sensor->getID() != ID)) {
        QMessageBox::warning(this, "ID Conflict", "The selected ID is already in use. Please choose a different ID.");
        return;
    }

    if (sensor) {
        // Modifica
        sensor->setName(name.toStdString());
        sensor->setDescription(description.toStdString());

        if (sensorType == "Temperatura") {
            if (auto tempSensor = dynamic_cast<Sensor::Temperatura*>(sensor)) {
                double tmin = tminLineEdit ? tminLineEdit->text().toDouble() : 0.0;
                double tmax = tmaxLineEdit ? tmaxLineEdit->text().toDouble() : 0.0;
                tempSensor->setTmin(tmin);
                tempSensor->setTmax(tmax);
            }
        }
        else if (sensorType == "Pressione") {
            if (auto pressSensor = dynamic_cast<Sensor::Pressione*>(sensor)) {
                double pmax = pmaxLineEdit ? pmaxLineEdit->text().toDouble() : 0.0;
                pressSensor->setPmax(pmax);
            }
        }
        else if (sensorType == "Carburante") {
            if (auto carbSensor = dynamic_cast<Sensor::Carburante*>(sensor)) {
                double soglia = sogliaLineEdit ? sogliaLineEdit->text().toDouble() : 0.0;
                double capacity = capacityLineEdit ? capacityLineEdit->text().toDouble() : 0.0;
                carbSensor->setSoglia(soglia);
                carbSensor->setCapacity(capacity);
            }
        }
        // Nessun modifica per PositionSensor

    } else {
        // Creazione di un nuovo sensore

        if (sensorType == "Temperatura") {
            double tmin = tminLineEdit ? tminLineEdit->text().toDouble() : 0.0;
            double tmax = tmaxLineEdit ? tmaxLineEdit->text().toDouble() : 0.0;
            sensor = new Sensor::Temperatura(name.toStdString(), description.toStdString(), ID, tmin, tmax);
        }
        else if (sensorType == "Pressione") {
            double pmax = pmaxLineEdit ? pmaxLineEdit->text().toDouble() : 0.0;
            sensor = new Sensor::Pressione(name.toStdString(), description.toStdString(), ID, pmax);
        }
        else if (sensorType == "Carburante") {
            double soglia = sogliaLineEdit ? sogliaLineEdit->text().toDouble() : 0.0;
            double capacity = capacityLineEdit ? capacityLineEdit->text().toDouble() : 0.0;
            sensor = new Sensor::Carburante(name.toStdString(), description.toStdString(), ID, capacity, soglia);
        }
        else if (sensorType == "Position") {
            sensor = new Sensor::PositionSensor(name.toStdString(), description.toStdString(), ID);
        }
        else {
            QMessageBox::warning(this, "Type Conflict", "You have to select the type of sensor");
            return;
        }
    }

    if (sensor) {
        Sensor::Repository::JsonRepository* repo = mainWindow->getRepository();
        repo->update(sensor);
        emit sensorSaved();

    }
}

void EditWidget::onCancelClicked() {
    emit editCanceled();
}

Sensor::AbstractSensor* EditWidget::getSensor() const { return sensor; }


}



