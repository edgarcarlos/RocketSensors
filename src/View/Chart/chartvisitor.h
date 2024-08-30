#ifndef CHARTVISITOR_H
#define CHARTVISITOR_H

#include "../../Sensor/IVisitor.h"
#include "chartpanel.h"

#include "../../Sensor/carburante.h"
#include "../../Sensor/pressione.h"
#include "../../Sensor/temperatura.h"
#include "../../Sensor/positionsensor.h"

namespace View{
namespace Chart{

class ChartVisitor: public Sensor::IVisitor
{
public:
    ChartVisitor(ChartPanel *chart);

    void visit(Sensor::Carburante& carburante) override;
    void visit(Sensor::Pressione& pressione) override;
    void visit(Sensor::Temperatura& temperatura) override;
    void visit(Sensor::PositionSensor& positionsensor) override;

private:
    ChartPanel *chart;
};

}
}

#endif // CHARTVISITOR_H
