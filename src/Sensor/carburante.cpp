#include "carburante.h"

namespace Sensor{

Carburante::Carburante(const std::string name,
                    const std::string description,
                    const unsigned int ID,
                    const double capacity,
                    const double soglio,
                    const std::vector<double> dati
                    ): LevelSensor(name,description,ID,capacity,dati),
                                    soglio(soglio) {}



double Carburante::debito(std::vector<double> dati) const{
    double difTotale = 0.0;
    
    for(unsigned int i=1; i<dati.size(); i++){
        difTotale = dati[i-1] - dati[i];
         
    }

    double tempoTot = dati.size()-1;
    
    return difTotale/tempoTot;
}

std::string Carburante::statoQuantita(double currentLevel) const{

    if(currentLevel <= soglio)
        return std::string("Basso");
        
    else return std::string("Sufficiente");
}

const double& Carburante::getSoglio() const{
    return soglio;
}

AbstractSensor& Carburante::setSoglio(const double soglio){
    this->soglio = soglio;
    return *this;
}

void Carburante::accept(SVisitor& visitor) {
    visitor.visit(*this);
}

void Carburante::accept(SConstVisitor& visitor) const {
    visitor.visit(*this);
}

}

