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
    //file->addAction(create);
    //file->addAction(open);
    //file->addAction(save);
    //file->addAction(save_as);
    //file->addSeparator();
    //file->addAction(close);

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




    mainLayout->addLayout(searchLayout, 0);











    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}
