#ifndef SENSORDETAILSVISITOR_H
#define SENSORDETAILSVISITOR_H

#include <QVBoxLayout>

#include "../Sensor/svisitor.h"
#include "sensordetails.h"

#include "../Sensor/carburante.h"
#include "../Sensor/pressione.h"
#include "../Sensor/temperatura.h"
#include "../Sensor/positionsensor.h"

namespace View {

class SensorDetailsVisitor : public Sensor::SVisitor
{
public:
    SensorDetailsVisitor(SensorDetails* window);

    void visit(Sensor::Carburante& carburante) override;
    void visit(Sensor::Pressione& pressione) override;
    void visit(Sensor::Temperatura& temperatura) override;
    void visit(Sensor::PositionSensor& positionsensor) override;

private:
    SensorDetails* window;
};

}
#endif // SENSORDETAILSVISITOR_H
