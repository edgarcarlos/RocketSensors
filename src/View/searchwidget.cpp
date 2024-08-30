#include "searchwidget.h"

namespace View {

SearchWidget::SearchWidget(QWidget *parent) : QWidget(parent) {


    layout = new QHBoxLayout(this);

    formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    layout->addLayout(formLayout);

    searchInput = new QLineEdit();
    formLayout->addRow("Search", searchInput);

    QPushButton* search_input = new QPushButton(QIcon(QPixmap((":Assets/icons/search_icon.png"))),
                                "Search");
    layout->addWidget(search_input);

    search_input->setShortcut(QKeySequence(Qt::Key_Return));


    // Filter menu
    filterMenu = new QMenu(this);
    filterMenu->setTitle("filter");

    QWidget *filterWidget = new QWidget();
    QVBoxLayout *filterLayout = new QVBoxLayout(filterWidget);
    //filterLayout->SetMinimumSize(150, 100);

    temperatura = new QCheckBox("Temperatura");
    pressione = new QCheckBox("Pressione");
    carburante = new QCheckBox("Carburante");
    position = new QCheckBox("Position");


    filterLayout->addWidget(temperatura);
    filterLayout->addWidget(pressione);
    filterLayout->addWidget(carburante);
    filterLayout->addWidget(position);

    filterWidget->setLayout(filterLayout);

    filterWidget->setMinimumSize(200, 150);
    filterWidget->resize(200, 150);

    QWidgetAction *filterAction = new QWidgetAction(filterMenu);
    filterAction->setDefaultWidget(filterWidget);
    filterMenu->addAction(filterAction);

    filterButton = new QToolButton();
    QIcon filterIcon(QPixmap(":Assets/icons/filter_icon.png"));

    filterButton->setIcon(filterIcon); // Définir l'icône
    filterButton->setText("Filter");   // Définir le texte
    filterButton->setMenu(filterMenu); // Définir le menu
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

    //disattivare il check quando si lancia una ricerca
    temperatura->setChecked(false);
    pressione->setChecked(false);
    carburante->setChecked(false);
    position->setChecked(false);

}


void SearchWidget::Checkboxchanged(){

    std::vector<QString> selectedTypes;

    if (temperatura->isChecked()) {
        selectedTypes.push_back("Temperatura");
    }
    if (pressione->isChecked()) {
        selectedTypes.push_back("Pressione");
    }
    if (carburante->isChecked()) {
        selectedTypes.push_back("Carburante");
    }
    if (position->isChecked()) {
        selectedTypes.push_back("Position");
    }

    emit filterTypesChanged(selectedTypes);
}

}
