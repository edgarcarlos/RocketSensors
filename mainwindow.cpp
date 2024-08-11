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

//#include <string>

//#include "abstractsensor.h"
#include "reader.h"
#include "json.h"
#include "jsonfile.h"

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
    connect(open, &QAction::triggered, this, &MainWindow::openData);
    connect(save, &QAction::triggered, this, &MainWindow::saveData);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveAsData);
    connect(close, &QAction::triggered, this, &MainWindow::close_);
    connect(fullScreen, &QAction::triggered, this, &MainWindow::setFullScreen);
    connect(add_sensor, &QAction::triggered, this, &MainWindow::addSensor);
    connect(searchWidget, &SearchWidget::searchTriggered, this, &MainWindow::search);

    //showStatus("Ready.");
}

MainWindow::~MainWindow()
{
}

/*Sensors::Repository::*/JsonRepository* MainWindow::getRepository() {
    return repository;
}

MainWindow& MainWindow::reloadData() {
    std::vector</*Sensor::*/AbstractSensor*> add_sensors(repository->readAll());
    for (auto it = sensors.begin(); it != sensors.end(); ++it ){
        sensors.push_back(*it);
    }
    return *this;
}

SearchWidget* MainWindow::getSearchWidget() {
    return searchWidget;
}

//Action functions
void MainWindow::openData(){

    QString path = QFileDialog::getOpenFileName(
        this,
        "Open Dataset",
        "./Assets/DataJson/",
        "JSON files *.json"
        );
    if (path.isEmpty()) {
        return;
    }
    if (repository != nullptr) {
        delete repository;
    }
    Reader reader;
    Json converter(reader);
    DataMapper::JsonFile data_mapper(path.toStdString(), converter);
    repository = new /*Sensor::Repository::*/JsonRepository(data_mapper);
    reloadData();

}

void MainWindow::saveData(){
    if (repository == nullptr) {
        return;
    }
    repository->store();
}

void MainWindow::saveAsData(){
    QString path = QFileDialog::getSaveFileName(
        this,
        "Creates new Dataset",
        "./",
        "JSON files *.json"
        );
    if (path.isEmpty() || repository == nullptr) {
        return;
    }
    repository->setPath(path.toStdString()).store();
}

void MainWindow::search(const std::string& query){

    if (!repository) {
        showStatus("No repository loaded.");
        return;
    }

    sensorspanel->clearResults();

    std::vector<AbstractSensor*> results;
    std::vector<AbstractSensor*> sensors = repository->readAll();

    for (AbstractSensor* sensor : sensors) {
        // Example search criteria: matching the sensor name
        if (sensor->getName().find(query) != std::string::npos ||
            std::to_string(sensor->getID()).find(query) != std::string::npos) {
            results.push_back(sensor);
        }
    }

    if (results.empty()) {
        showStatus("No matching sensors found.");
    } else {
        sensorspanel->addSensors(results);
        showStatus(QString::number(results.size()) + " matching sensors found.");
    }


}

void MainWindow::close_(){
    QApplication::quit();
}

void MainWindow::setFullScreen(){

    if (isFullScreenMode) {
        showNormal(); // Switch to normal window
        isFullScreenMode = false;
    } else {
        showFullScreen(); // Switch to full screen
        isFullScreenMode = true;
    }
}


void MainWindow::addSensor(){}





void MainWindow::showStatus(QString message) {
    statusBar()->showMessage(message);
}









