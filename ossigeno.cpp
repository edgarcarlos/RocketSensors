#include "ossigeno.h"

Ossigeno::Ossigeno(const string name,
                    const string description,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const bool qualita,
                    const double soglio): LevelSensor(name,description,ID,capacity,dati,currentLevel),
                                            qualita(qualita),
                                            soglio(soglio) {}

bool Ossigeno::isQualita()const {
    return qualita;
}

string Ossigeno::statoQuantita(double currentLevel)const {
   
    if(currentLevel <= soglio)
        return string("Basso");
        
    else return string("Sufficiente");
}

