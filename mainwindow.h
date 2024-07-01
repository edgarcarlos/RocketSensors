#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "searchwidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    SearchWidget* searchWidget;

public slots:
    void openFile();
    void saveFile();
    void saveAsFile();
    void closeFile();
    void setFullScreen();
};


#endif // MAINWINDOW_H
