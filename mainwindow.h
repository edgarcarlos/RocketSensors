#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "searchwidget.h"
#include "sensorspanel.h"
#include "jsonrepository.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    JsonRepository* getRepository();
    MainWindow& reloadData();
    SearchWidget* getSearchWidget();


private:
    QStackedWidget* stackedWidget;
    SearchWidget* searchWidget;
    SensorsPanel* sensorspanel;
    JsonRepository* repository;
    std::vector<AbstractSensor*> sensors;
    bool isFullScreenMode = false;

public slots:
    void showSensorWindow(AbstractSensor* sensor);
    void openData();
    void saveData();
    void saveAsData();
    void close_();
    void setFullScreen();
    void addSensor();
    void search(const std::string& query);
    void deleteSensor(const AbstractSensor* sensor);
    void modifySensor(AbstractSensor* sensor);
    void showStatus(QString message);
};


#endif // MAINWINDOW_H
