#include "sensorspanel.h"
#include "typeandiconvisitor.h"

#include <QGridLayout>

SensorsPanel::SensorsPanel(QWidget* parent): QWidget(parent) {

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    //scrollArea->setBackgroundRole(QPalette::Dark);

    content = new QWidget();
    panelLayout = new QGridLayout(content);
    panelLayout->setAlignment(Qt::AlignTop);
    panelLayout->setSpacing(15); // Espacement entre les widgets

    content->setLayout(panelLayout);

    scrollArea->setWidget(content);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);

    setLayout(mainLayout);

}


void SensorsPanel::addSensors(const std::vector<AbstractSensor*>& sensors){

    for (auto sensor : sensors) {
        // Créez un nouveau widget pour chaque capteur
        SensorWidget* sensorWidget = new SensorWidget(sensor, content);
        sensorWidget->setObjectName("sensorWidget");
        // Configurez le widget avec les informations du capteur
        TypeAndIconVisitor typeAndIconVisitor(sensorWidget);
        sensor->accept(typeAndIconVisitor);

        // Ajoutez le widget au layout
        panelLayout->addWidget(sensorWidget);

        // Connectez le signal 'selected' à la méthode 'showSensor'
        connect(sensorWidget, &SensorWidget::selected, this, &SensorsPanel::showSensor);
    }

    // Mettez à jour le layout pour organiser les nouveaux widgets
    updateLayout();

}

void SensorsPanel::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    updateLayout();
}

void SensorsPanel::updateLayout() {
    int row = 0;
    int col = 0;
    int rowSize = initialRowSize;
    if (width() > 600) {
        rowSize = width() / 200;
    }

    if (rowSize == 0) {
        rowSize = 1;
    }

    for (SensorWidget* widget : sensorWidgets) {
        panelLayout->addWidget(widget, row, col);
        col++;
        if (col >= rowSize) {
            col = 0;
            row++;
        }
    }
}


void SensorsPanel::showSensor(AbstractSensor* sensor) {
    SensorWindow* detailWindow = new SensorWindow(sensor);
    detailWindow->setAttribute(Qt::WA_DeleteOnClose);
    detailWindow->show();
}

void SensorsPanel::clearResults() {
    // Iterate over all items in the layout and remove each widget
    while (QLayoutItem* item = panelLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater(); // Mark widget for deletion
        }
        delete item; // Delete the layout item
    }
    sensorWidgets.clear(); // Clear the sensorWidgets vector
}






