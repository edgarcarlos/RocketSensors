#ifndef VELOCITA_H
#define VELOCITA_H

#include<string>
#include<vector>

#include "positionsensor.h"

using namespace std;

class Velocita: public PositionSensor {
    private:
        PositionSensor position;
        vector<double> altitudeDati;

    public:
        Velocita(string name,
                        string descrizione,
                        string logo_path,
                        string ID,
                        Localisation positionAttuale,
                        vector<Localisation> dati);
        double accelerazione(vector<double> altitudeDati);
        double velocitaMedia(vector<double> altitudeDati);
};

#endif // VELOCITA_H
