#include "carburante.h"

Carburante::Carburante(const string name,
                    const string descrizione,
                    const string logo_path,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const string unita,
                    const double soglio): LevelSensor(name,descrizione,logo_path,ID,capacity,dati,currentLevel,unita),
                                    soglio(soglio) {}



double Carburante::debito(vector<double> dati) const{
    double difTotale = 0.0;
    
    for(int i=1; i<dati.size(); i++){
        double difTotale = dati[i-1] - dati[i];
         
    }

    double tempoTot = dati.size()-1;
    
    return difTotale/tempoTot;
}

string Carburante::statoQuantita(double currentLevel) const{

    if(currentLevel <= soglio)
        return string("Basso");
        
    else string("Sufficiente");
}
