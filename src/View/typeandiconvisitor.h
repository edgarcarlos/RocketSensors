#ifndef TYPEANDICONVISITOR_H
#define TYPEANDICONVISITOR_H

#include "../Sensor/IVisitor.h"
#include "sensorwidget.h"
#include <QIcon>
#include <QString>

namespace View {

class TypeAndIconVisitor: public Sensor::IVisitor
{
public:
    TypeAndIconVisitor(SensorWidget* sensor);

    void visit(Sensor::Carburante& carburante) override;
    void visit(Sensor::Pressione& pressione) override;
    void visit(Sensor::Temperatura& temperatura) override;
    void visit(Sensor::PositionSensor& positionsensor) override;

private:
    SensorWidget* sensor;

};

}

#endif // TYPEANDICONVISITOR_H
