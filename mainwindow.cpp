#include "mainwindow.h"

#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QPixmap>
#include <QToolBar>

#include <string>

#include "abstractsensor.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    resize(600,400);


    //Menubar

    QAction* open = new QAction("Open", this);
    QAction* save = new QAction("Save", this);
    QAction* save_as = new QAction("Save_as", this);
    QAction* close = new QAction("close", this);
    QAction* add_sensor = new QAction("Add sensor", this);


    //QMenuBar* menuBar = new QMenuBar(this);
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu* file =  menuBar->addMenu("&File");

    //menuBar->addMenu(file);

    file->addAction(open);
    file->addAction(save);
    file->addAction(save_as);
    file->addAction(close);

    //View menu
    QMenu* view =  menuBar->addMenu("&View");
    QAction* fullScreen = new QAction("Full Screen", this);
    QAction* viewOption2 = new QAction("View Option 2", this);

    view->addAction(fullScreen);
    view->addAction(viewOption2);

    //Home Menu
    QMenu* home =  menuBar->addMenu("&Home");
    QAction* homeOption1 = new QAction("Home Option 1", this);
    QAction* homeOption2 = new QAction("Home Option 2", this);

    home->addAction(homeOption1);
    home->addAction(homeOption2);


    //Toolbar
    QToolBar* toolbar = new QToolBar(this);

    toolbar = addToolBar("File Toolbar");
    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(save_as);
    toolbar->addSeparator();
    toolbar->addAction(add_sensor);

    //set search Widget
    searchWidget = new SearchWidget(this);
    mainLayout->addWidget(searchWidget);

    //set sensor panel
    sensorspanel= new SensorsPanel(this);
    mainLayout->addWidget(sensorspanel);


    //connect Signals
    connect(open, &QAction::triggered, this, &MainWindow::openFile);
    connect(save, &QAction::triggered, this, &MainWindow::saveFile);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveAsFile);
    connect(close, &QAction::triggered, this, &MainWindow::closeFile);
    connect(fullScreen, &QAction::triggered, this, &MainWindow::setFullScreen);
    connect(add_sensor, &QAction::triggered, this, &MainWindow::addSensor);

}

MainWindow::~MainWindow()
{
}


//Action functions
void MainWindow::openFile(){}
void MainWindow::saveFile(){}
void MainWindow::saveAsFile(){}
void MainWindow::closeFile(){}
void MainWindow::setFullScreen(){}
void MainWindow::addSensor(){}
