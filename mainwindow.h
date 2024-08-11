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
    void showStatus(QString message);

private:

    SearchWidget* searchWidget;
    SensorsPanel* sensorspanel;
    JsonRepository* repository;
    std::vector<AbstractSensor*> sensors;
    bool isFullScreenMode = false;

public slots:
    void openData();
    void saveData();
    void saveAsData();
    void close_();
    void setFullScreen();
    void addSensor();
    void search(const std::string& query);
};


#endif // MAINWINDOW_H
