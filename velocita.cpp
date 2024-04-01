#include "velocita.h"

Velocita::Velocita(const string name,
                        const string descrizione,
                        const string logo_path,
                        const string ID,
                        const Localisation positionAttuale,
                        const vector<Localisation> dati,
                        const PositionSensor position,
                        const vector<double> altitudeDati): PositionSensor(name,descrizione,logo_path,ID,positionAttuale,dati), 
                                                            position(position),
                                                            altitudeDati(altitudeDati) {}


vector<double> Velocita::velocitaDati(const vector<double> altitudeDati) const {
        vector<double> velocita;
        if (altitudeDati.size() < 2) {
            return velocita;
        }

        for (int i = 1; i < altitudeDati.size(); ++i) {
            double spazio = altitudeDati[i] - altitudeDati[i - 1];
            double tempo = 1.0; //tempo costante fra le misure
            double vel = spazio / tempo;
            velocita.push_back(vel);
        }

        return velocita;
}        

double Velocita::velocitaMedia(vector<double> altitudeDati)const {

    double distanzaTotale = 0.0;
    
    for(int i=1; i<altitudeDati.size(); i++){
        double spazio = altitudeDati[i] - altitudeDati[i-1];
        distanzaTotale += spazio;
    }

    double tempoTot = altitudeDati.size()-1;
    
    return distanzaTotale/tempoTot;
}
 
double Velocita::accelerazione(vector<double> velocitaDati)const {
    double difTotale = 0.0;
    
    for(int i=1; i<velocitaDati.size(); i++){
        double difTotale = velocitaDati[i] - velocitaDati[i-1];
         
    }

    double tempoTot = velocitaDati.size()-1;
    
    return difTotale/tempoTot;


}