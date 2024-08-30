#ifndef POSITIONSENSOR_H
#define POSITIONSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

namespace Sensor{

class PositionSensor: public AbstractSensor {
    public:
        struct Localisation{
            double latitude;
            double longitude;
            double altitude;
        };
        
    private:
        std::vector<Localisation> dati;
         
    public:
        PositionSensor(const std::string name,
                       const std::string descrizione,
                       const unsigned int ID,
                       const std::vector<Localisation>& dati = {}
                       );
        const Localisation& getPosition()const ;
        const std::vector<Localisation> getDati()const ;
        double getAltitude()const ;
        double getLongitude()const ;
        double getLatitude()const ;
        void accept(SVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;

};
}

#endif // POSITIONSENSOR_H
