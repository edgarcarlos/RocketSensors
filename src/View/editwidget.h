#ifndef EDITWIDGET_H
#define EDITWIDGET_H

#include "../Sensor/abstractsensor.h"
#include "../Sensor/Repository/jsonrepository.h"
#include "mainwindow.h"

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

namespace View {

class EditWidget : public QWidget
{
    Q_OBJECT

private:
    MainWindow* mainWindow;
    Sensor::AbstractSensor* sensor;
    Sensor::Repository::JsonRepository* repository;
    QVBoxLayout* vboxlayout;
    QSpinBox* idEdit;
    QLineEdit* nameEdit;
    QLineEdit* descriptionEdit;
    QComboBox* typeComboBox;
    QVBoxLayout* dynamicFieldsLayout;
    QPushButton* saveButton;
    QPushButton* cancelButton;
    QString initialName;
    QString initialDescription;
    int initialID;

    void clearDynamicFields();
    void createTemperatureFields();
    void createPressionFields();
    void createCarburanteFields();
    void createPositionFields();
    void storeInitialValues();


    QLineEdit* tminLineEdit;
    QLineEdit* tmaxLineEdit;
    QLineEdit* pmaxLineEdit;
    QLineEdit* soglioLineEdit;
    QLineEdit* capacityLineEdit;


public:
    EditWidget(Sensor::AbstractSensor* sensor,
               MainWindow* mainWindow,
               Sensor::Repository::JsonRepository* repository,
               QWidget* parent = nullptr);
    Sensor::AbstractSensor* getSensor() const;

signals:
    void sensorSaved();
    void editCanceled();

public slots:
    void checkForChanges();
    void onSensorTypeChanged(const QString& sensorType);
    void apply();
    void onCancelClicked();
};
}

#endif // EDITWIDGET_H
