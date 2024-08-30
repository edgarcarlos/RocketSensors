#include "positionsensor.h"

namespace Sensor{

PositionSensor::PositionSensor(const std::string name,
                       const std::string description,
                       const unsigned int ID,
                       const std::vector<Localisation>& dati
                       ): AbstractSensor(name,description,ID), dati(dati) {}


const PositionSensor::Localisation& PositionSensor::getPosition()const {
    static PositionSensor::Localisation defaultPosition;
    if (!dati.empty())
        return dati.back();
    else
        return defaultPosition;
}


const std::vector<PositionSensor::Localisation> PositionSensor::getDati()const {
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

void PositionSensor::accept(SVisitor& visitor) {
    visitor.visit(*this);
}

void PositionSensor::accept(SConstVisitor& visitor) const {
    visitor.visit(*this);
}
}
