#include "searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent) : QWidget(parent) {


    layout = new QHBoxLayout(this);

    formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    layout->addLayout(formLayout);

    searchInput = new QLineEdit();
    formLayout->addRow("Search", searchInput);

    QPushButton* search_input = new QPushButton();
    layout->addWidget(search_input);

    // Filter menu
    filterMenu = new QMenu(this);
    filterMenu->setTitle("Filter");

    QWidget *filterWidget = new QWidget(filterMenu);
    QVBoxLayout *filterLayout = new QVBoxLayout(filterWidget);

    QCheckBox* temperatura = new QCheckBox("Temperatura");
    QCheckBox* pressione = new QCheckBox("pressione");
    QCheckBox* carburante = new QCheckBox("Carburante");
    QCheckBox* position = new QCheckBox("Position");

    filterLayout->addWidget(temperatura);
    filterLayout->addWidget(pressione);
    filterLayout->addWidget(carburante);
    filterLayout->addWidget(position);

    filterWidget->setLayout(filterLayout);
    QAction *filterAction = new QWidgetAction(filterMenu);
    //filterAction->setDefaultWidget(filterWidget);
    filterMenu->addAction(filterAction);

    filterButton = new QToolButton();
    filterButton->setText("Filter");
    filterButton->setMenu(filterMenu);
    filterButton->setPopupMode(QToolButton::InstantPopup);
    layout->addWidget(filterButton);


    //connect
    connect(search_input, &QPushButton::clicked, this, &SearchWidget::searchClicked);
    connect(temperatura, &QCheckBox::stateChanged, this, &SearchWidget::Checkboxchanged);
    connect(pressione, &QCheckBox::stateChanged, this, &SearchWidget::Checkboxchanged);
    connect(carburante, &QCheckBox::stateChanged, this, &SearchWidget::Checkboxchanged);
    connect(position, &QCheckBox::stateChanged, this, &SearchWidget::Checkboxchanged);


}


void SearchWidget::searchClicked(){

    std::string searchString = searchInput->text().toStdString();
    emit searchTriggered(searchString);
}


void SearchWidget::Checkboxchanged(){}
