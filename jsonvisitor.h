#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include <QJsonObject>

#include "abstractsensor.h"
#include "sconstvisitor.h"
#include "temperatura.h"
#include "pressione.h"
#include "carburante.h"
#include "positionsensor.h"


class JsonVisitor: public SConstVisitor
{
private:
    QJsonObject object;
public:
    QJsonObject getObject() const;
    void visit(const Carburante& carburante) override;
    void visit(const Pressione& pressione) override;
    void visit(const Temperatura& temperatura) override;
    void visit(const PositionSensor& positionsensor) override;

};

#endif // JSONVISITOR_H
