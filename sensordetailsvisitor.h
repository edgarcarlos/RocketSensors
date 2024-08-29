#ifndef SENSORDETAILSVISITOR_H
#define SENSORDETAILSVISITOR_H

#include <QVBoxLayout>
#include "IVisitor.h"
#include "sensordetails.h"

#include "carburante.h"
#include "pressione.h"
#include "temperatura.h"
#include "positionsensor.h"

class SensorDetailsVisitor : public IVisitor
{
public:
    SensorDetailsVisitor(SensorDetails* window);

    void visit(Carburante& carburante) override;
    void visit(Pressione& pressione) override;
    void visit(Temperatura& temperatura) override;
    void visit(PositionSensor& positionsensor) override;

private:
    SensorDetails* window;
};

#endif // SENSORDETAILSVISITOR_H
