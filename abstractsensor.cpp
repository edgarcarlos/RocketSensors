#include "abstractsensor.h"

using namespace std;

AbstractSensor::AbstractSensor(const string name,
                       const string descrizione,
                       const string logo_path,
                       const string ID): name(name), 
                                         descrizione(descrizione),
                                         logo_path(logo_path), 
                                         ID(ID) {}


AbstractSensor::~AbstractSensor() {}

const string& AbstractSensor::getName() const {
    return name;
}

AbstractSensor& AbstractSensor::setName(const string name){
    this->name;
    return *this;
}

const string& AbstractSensor::getDescrizione()const{
    return descrizione;
}

AbstractSensor& AbstractSensor::setDescrizione(const string descrizione){
    this->descrizione;
    return *this;
}

const string& AbstractSensor::getLogo()const {
    return logo_path;
}

const string& AbstractSensor::getID()const {
    return ID;
}

AbstractSensor& AbstractSensor::setID(const string ID){
    this->ID;
    return *this;
}




