#ifndef TYPEANDICONVISITOR_H
#define TYPEANDICONVISITOR_H

#include "IVisitor.h"
#include "sensorwidget.h"
#include <QIcon>
#include <QString>

class TypeAndIconVisitor: public IVisitor
{
public:
    TypeAndIconVisitor(SensorWidget* sensor);

    void visit(Carburante& carburante) override;
    void visit(Ossigeno& ossigeno) override;
    void visit(Pressione& pressione) override;
    void visit(Temperatura& temperatura) override;
    void visit(Umidita& umidita) override;
    void visit(Velocita& velocita) override;
    void visit(PositionSensor& positionsensor) override;

private:
    SensorWidget* sensor;

};

#endif // TYPEANDICONVISITOR_H
