#ifndef SVISITOR_H
#define SVISITOR_H

namespace Sensor{

class Carburante;
class Pressione;
class Temperatura;
class PositionSensor;



class SVisitor {
public :
    virtual ~SVisitor() {}
    virtual void visit(Carburante& carburante) =0;
    virtual void visit(Pressione& pressione) =0;
    virtual void visit(Temperatura& temperatura) =0;
    virtual void visit(PositionSensor& positionsensor) =0;
};
}

#endif // SVISITOR_H
