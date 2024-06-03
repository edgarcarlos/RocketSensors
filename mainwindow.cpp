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

    //Menubar

    //QMenuBar* menuBar = new QMenuBar(this);
    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu* file =  menuBar->addMenu("&File");


    //menuBar->addMenu(file);
    file->addAction(new QAction("new",file));
    file->addAction(new QAction("open",file));
    file->addAction(new QAction("save",file));
    file->addAction(new QAction("save as",file));
    file->addAction(new QAction("close",file));

    QMenu* view =  menuBar->addMenu("&View");
    QMenu* home =  menuBar->addMenu("&Home");

    //search layout

    QHBoxLayout* searchLayout = new QHBoxLayout(this);
    //searchLayout->setAlignment(Qt::AlignHCenter);


    QFormLayout* form = new QFormLayout();
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    searchLayout->addLayout(form);


    QLineEdit* query_input;
    query_input = new QLineEdit();
    form->addRow("Search", query_input);

    //filter menu
    QMenu* filterMenu = new QMenu(this);
    filterMenu->setTitle("Filter");

    QAction* option1Action = filterMenu->addAction("Option 1");
    QAction* option2Action = filterMenu->addAction("Option 2");


    QToolButton* filterButton = new QToolButton();
    filterButton->setText("Filter");
    filterButton->setMenu(filterMenu);
    filterButton->setPopupMode(QToolButton::InstantPopup); // Affichez le menu instantanément lors du clic
    searchLayout->addWidget(filterButton);

    //Item
    //ListItem

    QWidget* widget = new QWidget();

    QHBoxLayout* hbox = new QHBoxLayout(widget);

    QVBoxLayout* vbox = new QVBoxLayout();
    hbox->addLayout(vbox);

    QHBoxLayout* hbox2 = new QHBoxLayout();
    vbox->addLayout(hbox2);

    QLabel* logo = new QLabel();
    //logo->setPixmap();
    hbox2->addWidget(logo);

    const string nome = "temperatura";
    const string descrizione = "qwertyuiopp";
    const string logo_path = "adfgkernàoes";
    const string ID = "234";
    AbstractSensor Sensor(nome,descrizione,logo_path,ID);
    QLabel* name = new QLabel(QString::fromStdString(Sensor.getName()));
    name->setObjectName("name");
    hbox2->addWidget(name);

    QLabel* type = new QLabel();
    type->setText("type: TEmperature");
    vbox->addWidget(type);


    QLabel* des = new QLabel();
    des->setText("TEmperature mon cul");
    vbox->addWidget(des);

    //QLabel* media = new QLabel()




    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(widget);










    //setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}
