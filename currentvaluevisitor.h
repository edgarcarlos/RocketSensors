#ifndef CURRENTVALUEVISITOR_H
#define CURRENTVALUEVISITOR_H

#include "IVisitor.h"
#include "sensorwidget.h"
#include <QString>

#include "carburante.h"
#include "ossigeno.h"
#include "pressione.h"
#include "temperatura.h"
#include "umidita.h"
#include "velocita.h"
#include "positionsensor.h"

class CurrentValueVisitor: public IVisitor
{
public:
    CurrentValueVisitor(SensorWidget* widget);

    void visit(Carburante& carburante) override;
    void visit(Ossigeno& ossigeno) override;
    void visit(Pressione& pressione) override;
    void visit(Temperatura& temperatura) override;
    void visit(Umidita& umidita) override;
    void visit(Velocita& velocita) override;
    void visit(PositionSensor& positionsensor) override;

private:
    SensorWidget* widget;
};

#endif // CURRENTVALUEVISITOR_H
