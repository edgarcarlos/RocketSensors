#include "temperatura.h"

namespace Sensor{

Temperatura::Temperatura(const std::string name,
                    const std::string description,
                    const unsigned int ID,
                    const double Tmin,
                    const double Tmax,
                    const std::vector<double> dati): EnvSensor(name,description,ID,dati),
                                                Tmin(Tmin),
                                                Tmax(Tmax) {}

std::string Temperatura::stato(double valoreCorrente)const {

    if(valoreCorrente <= Tmin) return std::string("Basso");
    else if(Tmin < valoreCorrente && valoreCorrente < Tmax) return std::string("Normale");
    else if(valoreCorrente >= Tmax) return std::string("Elevato");
    else return std::string("errore");
}

const double& Temperatura::getTmin() const{
    return Tmin;
}
const double& Temperatura::getTmax() const{
    return Tmax;
}

AbstractSensor& Temperatura::setTmin(const double Tmin){
    this->Tmin = Tmin;
    return *this;
}
AbstractSensor& Temperatura::setTmax(const double Tmax){
    this->Tmax = Tmax;
    return *this;
}


void Temperatura::accept(SVisitor& visitor) {
    visitor.visit(*this);
}

void Temperatura::accept(SConstVisitor& visitor) const {
    visitor.visit(*this);
}

}
