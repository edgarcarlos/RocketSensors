#include "ossigeno.h"

Ossigeno::Ossigeno(const string name,
                    const string descrizione,
                    const string logo_path,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const string unita,
                    const bool qualita,
                    const double soglio): LevelSensor(name,descrizione,logo_path,ID,capacity,dati,currentLevel,unita),
                                            qualita(qualita),
                                            soglio(soglio) {}

bool Ossigeno::isQualita()const {
    return qualita;
}

string Ossigeno::statoQuantita(double currentLevel)const {
   
    if(currentLevel <= soglio)
        return string("Basso");
        
    else string("Sufficiente");
}

