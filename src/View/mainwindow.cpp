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
#include <QWidget>

#include "../Sensor/Converter/Json/reader.h"
#include "../Sensor/Converter/Json/json.h"
#include "../Sensor/DataMapper/jsonfile.h"
#include "editwidget.h"
#include "sensordetails.h"

namespace View {


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), repository(nullptr)

{

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    resize(1000,700);


    //Actions
    QAction* open = new QAction(
        QIcon(QPixmap((":Assets/icons/open_icon.png"))),
        "Open"
        );

    QAction* save = new QAction(
        QIcon(QPixmap((":Assets/icons/save_icon.png"))),
        "Save"
        );

    QAction* save_as =new QAction(
        QIcon(QPixmap((":Assets/icons/save_as_icon.png"))),
        "Save As"
        );
    QAction* close = new QAction(
        QIcon(QPixmap((":Assets/icons/close_icon.png"))),
        "Close"
        );
    add_sensor = new QAction(
        QIcon(QPixmap((":Assets/icons/add_icon.png"))),
        "Add sensor"
        );

    //Shortcut
    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    add_sensor->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_A));
    add_sensor->setEnabled(false);

    //menuBar
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    //File menu
    QMenu* file =  menuBar->addMenu("&File");

    file->addAction(open);
    file->addAction(save);
    file->addAction(save_as);
    file->addSeparator();
    file->addAction(add_sensor);
    file->addSeparator();
    file->addAction(close);

    //View menu
    QMenu* view =  menuBar->addMenu("&View");
    QAction* fullScreen = new QAction("Full Screen", this);
    QAction* toggle_toolbar = new QAction("Toggle ToolBar", this);

    view->addAction(fullScreen);
    view->addAction(toggle_toolbar);


    //Toolbar
    toolbar = new QToolBar(this);

    addToolBar(toolbar);
    toolbar->addAction(open);
    toolbar->addSeparator();
    toolbar->addAction(save);
    toolbar->addSeparator();
    toolbar->addAction(save_as);
    toolbar->addSeparator();
    toolbar->addAction(close);
    toolbar->addSeparator();
    toolbar->addAction(add_sensor);


    //set search and sensors panel
    searchWidget = new SearchWidget(this);
    mainLayout->addWidget(searchWidget);

    stackedWidget = new QStackedWidget(this);

    sensorspanel = new SensorsPanel(this);

    stackedWidget->addWidget(sensorspanel);
    mainLayout->addWidget(stackedWidget);


    //connect Signals
    connect(sensorspanel, &SensorsPanel::sensorClicked, this, &MainWindow::showSensorDetails);
    connect(open, &QAction::triggered, this, &MainWindow::openData);
    connect(save, &QAction::triggered, this, &MainWindow::saveData);
    connect(save_as, &QAction::triggered, this, &MainWindow::saveAsData);
    connect(close, &QAction::triggered, this, &MainWindow::close_);
    connect(fullScreen, &QAction::triggered, this, &MainWindow::setFullScreen);
    connect(toggle_toolbar, &QAction::triggered, this, &MainWindow::toggleToolbar);
    connect(add_sensor, &QAction::triggered, this, &MainWindow::addSensor);
    connect(searchWidget, &SearchWidget::searchTriggered, this, &MainWindow::search);
    connect(searchWidget, &SearchWidget::filterTypesChanged, this, &MainWindow::filterTypes);

    //status bar
    showStatus("Ready.");
}


void MainWindow::showSensorDetails(Sensor::AbstractSensor* sensor) {

    SensorDetails* sensorDetails = new SensorDetails(sensor, this);
    sensorDetails->setStackedWidget(stackedWidget);
    stackedWidget->addWidget(sensorDetails);
    stackedWidget->setCurrentWidget(sensorDetails);

    connect(sensorDetails, &SensorDetails::deleteSignal, this, &MainWindow::deleteSensor);
    connect(sensorDetails, &SensorDetails::modifySignal, this, &MainWindow::modifySensor);

}

Sensor::Repository::JsonRepository* MainWindow::getRepository() {
    return repository;
}

MainWindow& MainWindow::reloadData() {
    std::vector<Sensor::AbstractSensor*> add_sensors(repository->readAll());
    for (auto it = sensors.begin(); it != sensors.end(); ++it ){
        sensors.push_back(*it);
    }
    return *this;
}

SearchWidget* MainWindow::getSearchWidget() {
    return searchWidget;
}


void MainWindow::openData() {

    QString path = QFileDialog::getOpenFileName(
        this,
        "Open Dataset",
        "",
        "JSON files (*.json)"
    );


    if (path.isEmpty()) {
        showStatus("No file selected.");
        return;
    }

    if (repository != nullptr) {
        delete repository;
        qDebug() << "Ancien repository supprimé.";
    }

    try {
        Sensor::Converter::Json::Reader reader;
        Sensor::Converter::Json::Json converter(reader);
        Sensor::DataMapper::JsonFile data_mapper(path.toStdString(), converter);
        repository = new Sensor::Repository::JsonRepository(data_mapper);

        if (repository) {
            reloadData();
            add_sensor->setEnabled(true);

            showStatus("File loaded successfully.");
        } else {
            showStatus("Failed to initialize repository.");
        }

    } catch (...) {
        showStatus("An unknown error occurred.");

        if (repository != nullptr) {
            delete repository;
            repository = nullptr;
        }
    }
    search("");
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

    std::vector<Sensor::AbstractSensor*> results;
    std::vector<Sensor::AbstractSensor*> sensors = repository->readAll();

    //ricerca basata sul nome e l'ID
    for (Sensor::AbstractSensor* sensor : sensors) {
        if (query.empty() || sensor->getName().find(query) != std::string::npos ||
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


void MainWindow::filterTypes(const std::vector<QString>& types) {

    if (!repository) {
        showStatus("No repository loaded.");
        return;
    }

    sensorspanel->clearResults();

    std::vector<Sensor::AbstractSensor*> results;
    std::vector<Sensor::AbstractSensor*> sensors = repository->readAll();

    for (Sensor::AbstractSensor* sensor : sensors) {

        //creazione di un sensor widget per ottenere il type
        SensorWidget sensorWidget(sensor);
        QString sensorType = sensorWidget.getSensorType();

        //ricerca dei sensori con il tipo selezionato nei filtri

        bool matches = false;
        for (const auto& type : types) {
            if (sensorType == type) {
                matches = true;
                break;
            }
        }
        if (matches) {
            results.push_back(sensor);
        }
    }

    if (results.empty()) {
        showStatus("No matching sensors found.");
        search("");
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
        showNormal();
        isFullScreenMode = false;
    } else {
        showFullScreen();
        isFullScreenMode = true;
    }
}


void MainWindow::addSensor() {

    QDialog dialog(this);
    dialog.setWindowTitle("Add New Sensor");


    EditWidget* editWidget = new EditWidget(nullptr, this, repository, &dialog);
    if (!editWidget) {
        return;
    }

    connect(editWidget, &EditWidget::sensorSaved, &dialog, &QDialog::accept);
    connect(editWidget, &EditWidget::editCanceled, &dialog, &QDialog::reject);

    QVBoxLayout* vbox = new QVBoxLayout(&dialog);
    vbox->addWidget(editWidget);

    if (dialog.exec() == QDialog::Accepted) {

        Sensor::AbstractSensor* newSensor = editWidget->getSensor();

        if (newSensor) {
            std::vector<Sensor::AbstractSensor*> singleSensorVector = {newSensor};
            sensorspanel->addSensors(singleSensorVector);
            showStatus("New sensor added successfully.");

        } else {
            showStatus("Failed to create the sensor.");
        }
    } else {
        showStatus("Sensor creation canceled.");
    }
}


void MainWindow::deleteSensor(const Sensor::AbstractSensor* sensor) {
    showStatus("Sensor " + QString::fromStdString(sensor->getName()) + " removed.");
    repository->remove(sensor->getID());
    stackedWidget->setCurrentWidget(stackedWidget->widget(0));
    search("");

}


void MainWindow::modifySensor(Sensor::AbstractSensor* sensor){
    QDialog dialog(this);
    dialog.setWindowTitle("Modify Sensor");

    EditWidget* editWidget = new EditWidget(sensor,this,repository, &dialog);

    connect(editWidget, &EditWidget::sensorSaved, &dialog, &QDialog::accept);
    connect(editWidget, &EditWidget::editCanceled, &dialog, &QDialog::reject);

    QVBoxLayout* vbox = new QVBoxLayout(&dialog);
    vbox->addWidget(editWidget);

    if (dialog.exec() == QDialog::Accepted) {
        showStatus("Sensor modified successfully.");

        search("");
    } else {
        showStatus("Sensor modification canceled.");
    }
}


void MainWindow::showStatus(QString message) {
    statusBar()->showMessage(message);
}

void MainWindow::toggleToolbar() {
    toolbar->setVisible(!toolbar->isVisible());
    showStatus("Toolbar toggled.");
}

MainWindow::~MainWindow()
{
}

}








