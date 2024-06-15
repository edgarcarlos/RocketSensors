#ifndef SENSORWINDOWVISITOR_H
#define SENSORWINDOWVISITOR_H

#include "IVisitor.h"
#include "sensorwindow.h"

class SensorWindowVisitor : public IVisitor
{
public:
    SensorWindowVisitor(SensorWindow* window);

    void visit(Carburante& carburante) override;
    void visit(Ossigeno& ossigeno) override;
    void visit(Pressione& pressione) override;
    void visit(Temperatura& temperatura) override;
    void visit(Umidita& umidita) override;
    void visit(Velocita& velocita) override;
    void visit(Positionsensor& positionsensor) override;
};

#endif // SENSORWINDOWVISITOR_H
