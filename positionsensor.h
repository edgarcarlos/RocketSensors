#ifndef POSITIONSENSOR_H
#define POSITIONSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

using namespace std;

class PositionSensor: public AbstractSensor {
    protected:
        struct Localisation{
            double latitude;
            double longitude;
            double altitude;
        };
        
    private:
        Localisation positionAttuale;
        vector<Localisation> dati;
    
    
        
    public:
        PositionSensor(const string name,
                       const string descrizione,
                       const string ID,
                       const Localisation positionAttuale,
                       const vector<Localisation> dati);
        const Localisation& getPosition()const ;
        const vector<Localisation> getDati()const ;
        const double getAltitude()const ;
        const double getLongitude()const ;
        const double getLatitude()const ;
};

#endif // POSITIONSENSOR_H
