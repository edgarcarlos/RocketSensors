#include "abstractsensor.h"


using namespace std;

namespace Sensor{

AbstractSensor::AbstractSensor(const string name,
                       const string description,
                       const unsigned int ID): name(name),
                                         description(description),
                                         ID(ID) {}


AbstractSensor::~AbstractSensor() {}

const string& AbstractSensor::getName() const {
    return name;
}

AbstractSensor& AbstractSensor::setName(const string name){
    this->name = name;
    return *this;
}

const string& AbstractSensor::getDescription()const{
    return description;
}

AbstractSensor& AbstractSensor::setDescription(const string description){
    this->description = description;
    return *this;
}

unsigned int AbstractSensor::getID()const {
    return ID;
}

}




