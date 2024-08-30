#include "positionsensor.h"
namespace Sensor{

PositionSensor::PositionSensor(const string name,
                       const string description,
                       const unsigned int ID,
                       const vector<Localisation>& dati,
                       const Localisation& positionAttuale
                       ): AbstractSensor(name,description,ID),
                                                        positionAttuale(positionAttuale),
                                                        dati(dati) {}

       
 const PositionSensor::Localisation& PositionSensor::getPosition()const {
    static PositionSensor::Localisation defaultPosition;
    if (!dati.empty())
        return dati.back();
    else
        return defaultPosition;
 }


const vector<PositionSensor::Localisation> PositionSensor::getDati()const {
    return dati;
}

double PositionSensor::getAltitude()const {
    return getPosition().altitude;
}

double PositionSensor::getLongitude()const {
    return getPosition().longitude;
}

double PositionSensor::getLatitude()const {
    return getPosition().latitude;
}

void PositionSensor::accept(IVisitor& visitor) {
    visitor.visit(*this);
}

void PositionSensor::accept(SConstVisitor& visitor) const {
    visitor.visit(*this);
}
}
