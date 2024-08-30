#ifndef SCONSTVISITOR_H
#define SCONSTVISITOR_H

namespace Sensor{

class Carburante;
class Pressione;
class Temperatura;
class PositionSensor;


class SConstVisitor
{
public:
    virtual ~SConstVisitor() {};
    virtual void visit(const Temperatura& temperatura) = 0;
    virtual void visit(const Pressione& pressione) = 0;
    virtual void visit(const Carburante& carburante) = 0;
    virtual void visit(const PositionSensor& positionSensor) = 0;
};

}
#endif // SCONSTVISITOR_H
