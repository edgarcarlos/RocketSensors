#ifndef POSITIONSENSOR_H
#define POSITIONSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

using namespace std;

class PositionSensor: public AbstractSensor {
    public:
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
                       const unsigned int ID,
                       const vector<Localisation>& dati = {},
                       const Localisation& positionAttuale = {0.0, 0.0, 0.0}

                       );
        const Localisation& getPosition()const ;
        const vector<Localisation> getDati()const ;
        double getAltitude()const ;
        double getLongitude()const ;
        double getLatitude()const ;
        void accept(IVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;

};

#endif // POSITIONSENSOR_H
