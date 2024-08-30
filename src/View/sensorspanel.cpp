#include "sensorspanel.h"
#include "typeandiconvisitor.h"
#include "sensordetails.h"

#include <QGridLayout>

namespace View {

SensorsPanel::SensorsPanel(QWidget* parent): QWidget(parent) {

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    content = new QWidget();

    panelLayout = new QGridLayout(content);
    panelLayout->setAlignment(Qt::AlignTop);
    panelLayout->setSpacing(15);

    content->setLayout(panelLayout);

    scrollArea->setWidget(content);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);

    setLayout(mainLayout);

}


void SensorsPanel::addSensors(const std::vector<Sensor::AbstractSensor*>& sensors){

    for (auto sensor : sensors) {
        // nuovo widget per ogni sensore

        SensorWidget* sensorWidget = new SensorWidget(sensor, content);
        sensorWidget->setObjectName("sensorWidget");

        // aggiunto di icon e label type
        TypeAndIconVisitor typeAndIconVisitor(sensorWidget);
        sensor->accept(typeAndIconVisitor);

        // aggiunto del widget al layout
        sensorWidgets.push_back(sensorWidget);

        // Connect
        connect(sensorWidget, &SensorWidget::selected, this, [this, sensor]() {
            emit sensorClicked(sensor);
        });
    }

    updateLayout();

}

void SensorsPanel::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    updateLayout();
}

void SensorsPanel::updateLayout() {

    //aggiornamento del layout per una disposizione a tre colonne

    while (QLayoutItem* item = panelLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            panelLayout->removeWidget(widget);
        }
        delete item;
    }

    int row = 0;
    int col = 0;
    int rowSize = 3;


    for (SensorWidget* widget : sensorWidgets) {
        panelLayout->addWidget(widget, row, col);
        col++;
        if (col >= rowSize) {
            col = 0;
            row++;
        }
    }
}


void SensorsPanel::showSensor(Sensor::AbstractSensor* sensor) {

    SensorDetails* detailWindow = new SensorDetails(sensor);
    detailWindow->setAttribute(Qt::WA_DeleteOnClose);
    detailWindow->show();
}

void SensorsPanel::clearResults() {

    while (QLayoutItem* item = panelLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    sensorWidgets.clear();
}


}



