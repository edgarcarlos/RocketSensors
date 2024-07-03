#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "searchwidget.h"
#include "sensorspanel.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    SearchWidget* searchWidget;
    SensorsPanel* sensorspanel;

public slots:
    void openFile();
    void saveFile();
    void saveAsFile();
    void closeFile();
    void setFullScreen();
    void addSensor();
};


#endif // MAINWINDOW_H
