#include "positionsensor.h"

PositionSensor::PositionSensor(const string name,
                       const string description,
                       const string ID,
                       const Localisation positionAttuale,
                       const vector<Localisation> dati): AbstractSensor(name,description,ID),
                                                        positionAttuale(positionAttuale),
                                                        dati(dati) {}

       
 const PositionSensor::Localisation& PositionSensor::getPosition()const {
    return positionAttuale;
 }

const vector<PositionSensor::Localisation> PositionSensor::getDati()const {
    return dati;
}

const double PositionSensor::getAltitude()const {
    return positionAttuale.altitude;
}
