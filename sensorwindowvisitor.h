#ifndef SENSORWINDOWVISITOR_H
#define SENSORWINDOWVISITOR_H

#include <QVBoxLayout>
#include "IVisitor.h"
//#include "sensorwindow.h"

#include "carburante.h"
#include "ossigeno.h"
#include "pressione.h"
#include "temperatura.h"
#include "umidita.h"
#include "velocita.h"
#include "positionsensor.h"

class SensorWindowVisitor : public IVisitor
{
public:
    SensorWindowVisitor(QVBoxLayout* layout);

    void visit(Carburante& carburante) override;
    void visit(Ossigeno& ossigeno) override;
    void visit(Pressione& pressione) override;
    void visit(Temperatura& temperatura) override;
    void visit(Umidita& umidita) override;
    void visit(Velocita& velocita) override;
    void visit(PositionSensor& positionsensor) override;

private:
    QVBoxLayout* infoLayout;
};

#endif // SENSORWINDOWVISITOR_H
