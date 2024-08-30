#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "searchwidget.h"
#include "sensorspanel.h"
#include "../Sensor/Repository/jsonrepository.h"

namespace View {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Sensor::Repository::JsonRepository* getRepository();
    MainWindow& reloadData();
    SearchWidget* getSearchWidget();


private:
    QStackedWidget* stackedWidget;
    SearchWidget* searchWidget;
    SensorsPanel* sensorspanel;
    Sensor::Repository::JsonRepository* repository;
    std::vector<Sensor::AbstractSensor*> sensors;
    bool isFullScreenMode = false;

public slots:
    void showSensorDetails(Sensor::AbstractSensor* sensor);
    void openData();
    void saveData();
    void saveAsData();
    void close_();
    void setFullScreen();
    void addSensor();
    void search(const std::string& query);
    void filterTypes(const std::vector<QString>& types);
    void deleteSensor(const Sensor::AbstractSensor* sensor);
    void modifySensor(Sensor::AbstractSensor* sensor);
    void showStatus(QString message);
};
}

#endif // MAINWINDOW_H
