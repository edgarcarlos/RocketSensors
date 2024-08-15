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
#include "editwidget.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), repository(nullptr)

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

    addToolBar(toolbar);
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

    showStatus("Ready.");
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
void MainWindow::openData() {
    qDebug() << "Début de openData()";

    QString path = QFileDialog::getOpenFileName(
        this,
        "Open Dataset",
        "",
        "JSON files (*.json)"
        );

    qDebug() << "Chemin du fichier sélectionné:" << path;

    if (path.isEmpty()) {
        showStatus("No file selected.");
        return;
    }

    // Supprimez le repository existant s'il existe
    if (repository != nullptr) {
        delete repository;
        qDebug() << "Ancien repository supprimé.";
    }

    try {
        Reader reader;
        Json converter(reader);
        DataMapper::JsonFile data_mapper(path.toStdString(), converter);
        repository = new JsonRepository(data_mapper);

        if (repository) {
            reloadData();
            showStatus("File loaded successfully.");
            qDebug() << "Données rechargées avec succès.";
        } else {
            showStatus("Failed to initialize repository.");
            qDebug() << "Échec de l'initialisation du repository.";
        }
    } catch (const std::exception& e) {
        showStatus(QString("Error: %1").arg(e.what()));
        qDebug() << "Exception attrapée:" << e.what();

        // En cas d'erreur, supprimez le repository pour éviter les utilisations ultérieures
        if (repository != nullptr) {
            delete repository;
            repository = nullptr;
            qDebug() << "Repository supprimé après l'erreur.";
        }
    } catch (...) {
        showStatus("An unknown error occurred.");
        qDebug() << "Erreur inconnue rencontrée.";

        // Même traitement en cas d'erreur inconnue
        if (repository != nullptr) {
            delete repository;
            repository = nullptr;
            qDebug() << "Repository supprimé après l'erreur inconnue.";
        }
    }
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


void MainWindow::addSensor() {
    // Créer un EditWidget directement dans une QDialog
    QDialog dialog(this);
    dialog.setWindowTitle("Add New Sensor");

    EditWidget* editWidget = new EditWidget(nullptr,this,repository, &dialog);

    // Ajouter des boutons "Save" et "Cancel" dans le QDialog
    connect(editWidget, &EditWidget::sensorSaved, &dialog, &QDialog::accept);
    connect(editWidget, &EditWidget::editCanceled, &dialog, &QDialog::reject);

    // Disposition du layout dans le QDialog
    QVBoxLayout* vbox = new QVBoxLayout(&dialog);
    vbox->addWidget(editWidget);

    // Afficher le dialogue en mode modal et attendre l'interaction de l'utilisateur
    if (dialog.exec() == QDialog::Accepted) {
        // Récupérer le capteur créé
        AbstractSensor* newSensor = editWidget->getSensor();

        if (newSensor) {

            // Créer un vecteur temporaire avec le capteur unique
            std::vector<AbstractSensor*> singleSensorVector = {newSensor};

            // Ajouter le capteur à l'interface utilisateur (SensorsPanel)
            sensorspanel->addSensors(singleSensorVector);

            // Afficher un message de succès
            showStatus("New sensor added successfully.");
        } else {
            showStatus("Failed to create the sensor.");
        }
    } else {
        // Si l'utilisateur annule
        showStatus("Sensor creation canceled.");
    }
}






void MainWindow::showStatus(QString message) {
    statusBar()->showMessage(message);
}









