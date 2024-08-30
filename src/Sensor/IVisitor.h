#ifndef IVISITOR_H
#define IVISITOR_H

namespace Sensor{

class Carburante;
class Pressione;
class Temperatura;
class PositionSensor;



class IVisitor {
public :
    virtual ~IVisitor() {}
    virtual void visit(Carburante& carburante) =0;
    virtual void visit(Pressione& pressione) =0;
    virtual void visit(Temperatura& temperatura) =0;
    virtual void visit(PositionSensor& positionsensor) =0;
};
}

#endif // IVISITOR_H
