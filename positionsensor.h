#ifndef POSITIONSENSOR_H
#define POSITIONSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

using namespace std;

class PositionSensor: public AbstractSensor {
    private:
        struct Localisation{
            double latitude;
            double longitude;
            double altitude;
        };
        Localisation positionAttuale;
        vector<Localisation> dati;
        
    public:
        PositionSensor(string name,
                       string descrizione,
                       string logo_path,
                       string ID,
                       Localisation positionAttuale,
                       vector<Localisation> dati);
        Localisation& getPosition();
        vector<Localisation> getDati();
        double getAltitude();
};

#endif // POSITIONSENSOR_H
