#include "sensorspanel.h"
#include "typeandiconvisitor.h"
#include <QGridLayout>

SensorsPanel::SensorsPanel(QWidget* parent): QWidget(parent) {

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setBackgroundRole(QPalette::Dark);
    content = new QWidget(scrollArea);

    panelLayout = new QGridLayout(content);
    panelLayout->setAlignment(Qt::AlignTop);
    content->setLayout(panelLayout);
    scrollArea->setWidget(content);

    setLayout(panelLayout);


}


void SensorsPanel::addSensors(const std::vector<AbstractSensor*>& sensors){

    std::vector<SensorWidget*> sensorWidgets;

    for(auto sensor : sensors){

        SensorWidget* sensorWidget = new SensorWidget(sensor, content);
        //sensorWidget->setName(QString::fromStdString(sensor->getName()));
        //sensorWidget->setId(sensor->getIdentifier());

        TypeAndIconVisitor TypeAndIconVisitor(sensorWidget);
        sensor->accept(TypeAndIconVisitor);

        sensorWidgets.push_back(sensorWidget);
        panelLayout->addWidget(sensorWidget);

        connect(sensorWidget, &SensorWidget::selected, this, &SensorsPanel::showSensor);

    }
    updateLayout();

    //for (SensorWidget* sensorWidget : sensorWidgets) {
    //    connect(sensorWidget, &SensorWidget::selected, this, &SensorsPanel::showSensor);
    //}

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




