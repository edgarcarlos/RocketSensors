#include "mainwindow.h"

#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    QVBoxLayout* mainLayout = new QVBoxLayout;

    //Menubar

    //QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file =  menuBar()->addMenu("&File");
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

    QMenu* view =  menuBar()->addMenu("&View");
    QMenu* home =  menuBar()->addMenu("&Home");

    //search layout

    QHBoxLayout* searchLayout = new QHBoxLayout;
    searchLayout->setAlignment(Qt::AlignHCenter);


    QFormLayout* form = new QFormLayout();
    searchLayout->addLayout(form);

    QLabel* title_label = new QLabel("Search Engine");
    title_label->setObjectName("title");
    title_label->setAlignment(Qt::AlignHCenter);
    searchLayout->addWidget(title_label);

    QLineEdit* query_input;
    query_input = new QLineEdit();
    form->addRow("Search", query_input);


    mainLayout->addLayout(searchLayout);











    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}
