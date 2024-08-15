#ifndef EDITWIDGET_H
#define EDITWIDGET_H

#include <QWidget>
#include "abstractsensor.h"
#include "jsonrepository.h"
#include "mainwindow.h"

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

class EditWidget : public QWidget
{
    Q_OBJECT

private:
    MainWindow* mainWindow;
    AbstractSensor* sensor;
    JsonRepository* repository;
    QVBoxLayout* vboxlayout;
    QSpinBox* idEdit;
    QLineEdit* nameEdit;
    QLineEdit* descriptionEdit;
    QComboBox* typeComboBox;
    QVBoxLayout* dynamicFieldsLayout;
    QPushButton* saveButton;
    QPushButton* cancelButton;

    void clearDynamicFields();
    void createTemperatureFields();
    void createPressionFields();
    void createCarburanteFields();
    void createPositionFields();

    QLineEdit* tminLineEdit;
    QLineEdit* tmaxLineEdit;
    QLineEdit* pmaxLineEdit;
    QLineEdit* soglioLineEdit;
    QLineEdit* capacityLineEdit;


public:
    EditWidget(AbstractSensor* sensor,
               MainWindow* mainWindow,
               JsonRepository* repository,
               QWidget* parent = nullptr);
    AbstractSensor* getSensor() const;

signals:
    void sensorSaved();
    void editCanceled();

public slots:
    void onSensorTypeChanged(const QString& sensorType);
    void apply();
    void onCancelClicked();
};

#endif // EDITWIDGET_H
