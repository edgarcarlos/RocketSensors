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
        Velocita(const string name,
                        const string description,
                        const unsigned int ID,
                        const Localisation positionAttuale,
                        const vector<Localisation> dati,
                        const PositionSensor position,
                        const vector<double> altitudeDati);

        vector<double> velocitaDati(const vector<double> altitudeDati) const ;
        double accelerazione(vector<double> velocitaDati)const ;
        double velocitaMedia()const ;
        void accept(IVisitor& visitor) override;
};

#endif // VELOCITA_H
