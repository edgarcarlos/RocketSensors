#include "carburante.h"

namespace Sensor{

Carburante::Carburante(const std::string name,
                    const std::string description,
                    const unsigned int ID,
                    const double capacity,
                    const double soglia,
                    const std::vector<double> dati
                    ): LevelSensor(name,description,ID,capacity,dati),
                                    soglia(soglia) {}



double Carburante::flusso(std::vector<double> dati) const{
    double difTotale = 0.0;
    
    for(unsigned int i=1; i<dati.size(); i++){
        difTotale = dati[i-1] - dati[i];
         
    }

    double tempoTot = dati.size()-1;
    
    return difTotale/tempoTot;
}

std::string Carburante::statoQuantita(double currentLevel) const{

    if(currentLevel <= soglia)
        return std::string("Basso");
        
    else return std::string("Sufficiente");
}

const double& Carburante::getSoglia() const{
    return soglia;
}

AbstractSensor& Carburante::setSoglia(const double soglia){
    this->soglia = soglia;
    return *this;
}

void Carburante::accept(SVisitor& visitor) {
    visitor.visit(*this);
}

void Carburante::accept(SConstVisitor& visitor) const {
    visitor.visit(*this);
}

}

