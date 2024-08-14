#ifndef SENSORWINDOWVISITOR_H
#define SENSORWINDOWVISITOR_H

#include <QVBoxLayout>
#include "IVisitor.h"
#include "sensorwindow.h"

#include "carburante.h"
#include "pressione.h"
#include "temperatura.h"
#include "positionsensor.h"

class SensorWindowVisitor : public IVisitor
{
public:
    SensorWindowVisitor(SensorWindow* window);

    void visit(Carburante& carburante) override;
    void visit(Pressione& pressione) override;
    void visit(Temperatura& temperatura) override;
    void visit(PositionSensor& positionsensor) override;

private:
    SensorWindow* window;
};

#endif // SENSORWINDOWVISITOR_H
