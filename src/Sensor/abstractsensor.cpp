#include "abstractsensor.h"

namespace Sensor{

AbstractSensor::AbstractSensor(const std::string name,
                       const std::string description,
                       const unsigned int ID): name(name),
                                         description(description),
                                         ID(ID) {}


AbstractSensor::~AbstractSensor() {}

const std::string& AbstractSensor::getName() const {
    return name;
}

AbstractSensor& AbstractSensor::setName(const std::string name){
    this->name = name;
    return *this;
}

const std::string& AbstractSensor::getDescription()const{
    return description;
}

AbstractSensor& AbstractSensor::setDescription(const std::string description){
    this->description = description;
    return *this;
}

unsigned int AbstractSensor::getID()const {
    return ID;
}

}




