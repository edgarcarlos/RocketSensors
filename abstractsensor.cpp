#include "abstractsensor.h"

using namespace std;

AbstractSensor::AbstractSensor(const string name,
                       const string description,
                       const string ID): name(name), 
                                         description(description),
                                         ID(ID) {}


AbstractSensor::~AbstractSensor() {}

const string& AbstractSensor::getName() const {
    return name;
}

AbstractSensor& AbstractSensor::setName(const string name){
    this->name;
    return *this;
}

const string& AbstractSensor::getDescription()const{
    return description;
}

AbstractSensor& AbstractSensor::setDescription(const string description){
    this->description;
    return *this;
}

const string& AbstractSensor::getID()const {
    return ID;
}

AbstractSensor& AbstractSensor::setID(const string ID){
    this->ID;
    return *this;
}




