#ifndef ITEM_I_VISITOR_H
#define ITEM_I_VISITOR_H


class Carburante;
class Ossigeno;
class Pressione;
class Temperatura;
class Umidita;
class Velocita;
class Positionsensor;

class IVisitor {
public :
    virtual ~IVisitor() {}
    virtual void visit(Carburante& carburante) =0;
    virtual void visit(Ossigeno& ossigeno) =0;
    virtual void visit(Pressione& pressione) =0;
    virtual void visit(Temperatura& temperatura) =0;
    virtual void visit(Umidita& umidita) =0;
    virtual void visit(Velocita& velocita) =0;
    virtual void visit(Positionsensor& positionsensor) =0;
}

#endif 
