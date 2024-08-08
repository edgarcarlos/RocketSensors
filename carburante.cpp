#include "carburante.h"

Carburante::Carburante(const string name,
                    const string description,
                    const unsigned int ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const double soglio): LevelSensor(name,description,ID,capacity,dati,currentLevel),
                                    soglio(soglio) {}



double Carburante::debito(vector<double> dati) const{
    double difTotale = 0.0;
    
    for(unsigned int i=1; i<dati.size(); i++){
        difTotale = dati[i-1] - dati[i];
         
    }

    double tempoTot = dati.size()-1;
    
    return difTotale/tempoTot;
}

string Carburante::statoQuantita(double currentLevel) const{

    if(currentLevel <= soglio)
        return string("Basso");
        
    else return string("Sufficiente");
}

const double& Carburante::getSoglio() const{
    return soglio;
}

