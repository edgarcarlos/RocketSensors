#ifndef CHARTVISITOR_H
#define CHARTVISITOR_H

#include "IVisitor.h"
#include "chartpanel.h"

#include "carburante.h"
#include "ossigeno.h"
#include "pressione.h"
#include "temperatura.h"
#include "umidita.h"
#include "velocita.h"
#include "positionsensor.h"

class ChartVisitor: public IVisitor
{
public:
    ChartVisitor(ChartPanel *chart);

    void visit(Carburante& carburante) override;
    void visit(Ossigeno& ossigeno) override;
    void visit(Pressione& pressione) override;
    void visit(Temperatura& temperatura) override;
    void visit(Umidita& umidita) override;
    void visit(Velocita& velocita) override;
    void visit(PositionSensor& positionsensor) override;

private:
    ChartPanel *chart;
};

#endif // CHARTVISITOR_H
