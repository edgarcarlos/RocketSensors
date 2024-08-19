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

    resize(1000,700);


    //Menubar

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
    QAction* add_sensor = new QAction(
        QIcon(QPixmap((":Assets/icons/add_icon.png"))),
        "Add sensor"
        );


    open->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    save_as->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));
    close->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    add_sensor->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_N));


    //QMenuBar* menuBar = new QMenuBar(this);
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu* file =  menuBar->addMenu("&File");

    //menuBar->addMenu(file);

    file->addAction(open);
    file->addAction(save);
    file->addAction(save_as);
    file->addSeparator();
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
    toolbar->addSeparator();
    toolbar->addAction(save);
    toolbar->addSeparator();
    toolbar->addAction(save_as);
    toolbar->addSeparator();
    toolbar->addAction(close);
    toolbar->addSeparator();
    toolbar->addAction(add_sensor);


     // Assurez-vous de remplacer par votre propre widget
        //set search Widget
    searchWidget = new SearchWidget(this);
    mainLayout->addWidget(searchWidget);

    stackedWidget = new QStackedWidget(this);

    // Assurez-vous de remplacer par votre propre widget
    sensorspanel = new SensorsPanel(this);

    stackedWidget->addWidget(sensorspanel);
    mainLayout->addWidget(stackedWidget);


    //set sensor panel
    //sensorspanel= new SensorsPanel(this);
    //mainLayout->addWidget(sensorspanel);


    //connect Signals
    connect(sensorspanel, &SensorsPanel::sensorClicked, this, &MainWindow::showSensorWindow);

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

void MainWindow::showSensorWindow(AbstractSensor* sensor) {
    SensorWindow* sensorWindow = new SensorWindow(sensor, this);
    sensorWindow->setStackedWidget(stackedWidget);  // Définir le QStackedWidget
    stackedWidget->addWidget(sensorWindow);
    stackedWidget->setCurrentWidget(sensorWindow);

    connect(sensorWindow, &SensorWindow::deleteSignal, this, &MainWindow::deleteSensor);
    connect(sensorWindow, &SensorWindow::modifySignal, this, &MainWindow::modifySensor);

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

    std::vector<AbstractSensor*> results;
    std::vector<AbstractSensor*> sensors = repository->readAll();

    for (AbstractSensor* sensor : sensors) {
        // Example search criteria: matching the sensor name
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


void MainWindow::deleteSensor(const AbstractSensor* sensor) {
    showStatus("Sensor " + QString::fromStdString(sensor->getName()) + " removed.");
    repository->remove(sensor->getID());
    stackedWidget->setCurrentWidget(stackedWidget->widget(0));
    search("");

}

void MainWindow::modifySensor(AbstractSensor* sensor){
    QDialog dialog(this);
    dialog.setWindowTitle("Modify Sensor");

    EditWidget* editWidget = new EditWidget(sensor,this,repository, &dialog);

    connect(editWidget, &EditWidget::sensorSaved, &dialog, &QDialog::accept);
    connect(editWidget, &EditWidget::editCanceled, &dialog, &QDialog::reject);

    QVBoxLayout* vbox = new QVBoxLayout(&dialog);
    vbox->addWidget(editWidget);

    if (dialog.exec() == QDialog::Accepted) {
        // Si la modification est acceptée
        showStatus("Sensor modified successfully.");

        // Optionnel : Vous pouvez actualiser l'interface utilisateur après la modification
        search("");  // Recherchez tous les capteurs pour rafraîchir la vue
    } else {
        // Si l'utilisateur annule la modification
        showStatus("Sensor modification canceled.");
    }
}


void MainWindow::showStatus(QString message) {
    statusBar()->showMessage(message);
}









