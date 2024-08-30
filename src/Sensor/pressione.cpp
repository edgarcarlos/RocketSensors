#include "pressione.h"

namespace Sensor{

double Pressione::pressioneAtmos = 101325.0;

Pressione::Pressione(const std::string name,
            const std::string description,
            const unsigned int ID,
            const double Pmax,
            const std::vector<double> dati
            ): EnvSensor(name,description,ID,dati), Pmax(Pmax) {}


std::vector<double> Pressione::pressioneAssoluta(std::vector<double> dati)const {

    std::vector<double> A;
    double pressioneA;

    for(unsigned int i = 0; i<dati.size(); i++){
        pressioneA = dati[i] + pressioneAtmos;
        A.push_back(pressioneA);
    }

    return A;
}

const double& Pressione::getPmax() const{
    return Pmax;
}

AbstractSensor& Pressione::setPmax(const double Pmax){
    this->Pmax = Pmax;
    return *this;
}


void Pressione::accept(SVisitor& visitor) {
    visitor.visit(*this);
}

void Pressione::accept(SConstVisitor& visitor) const {
    visitor.visit(*this);
}

}
