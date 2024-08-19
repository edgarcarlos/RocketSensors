#include "temperatura.h"

Temperatura::Temperatura(const string name,
                    const string description,
                    const unsigned int ID,
                    const double Tmin,
                    const double Tmax,
                    const vector<double> dati,
                    const double valoreCorrente): EnvSensor(name,description,ID,dati,valoreCorrente),
                                        Tmin(Tmin),
                                        Tmax(Tmax) {}

string Temperatura::stato(double valoreCorrente)const {

    if(valoreCorrente <= Tmin) return string("Basso");
    else if(Tmin < valoreCorrente && valoreCorrente < Tmax) return string("Normale");
    else if(valoreCorrente >= Tmax) return string("Elevato");
    else return string("errore");
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


void Temperatura::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

void Temperatura::accept(SConstVisitor& visitor) const {
    visitor.visit(*this);
}
