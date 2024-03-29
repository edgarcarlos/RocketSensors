#include "levelsensor.h"

LevelSensor::LevelSensor(const string name,
                    const string descrizione,
                    const string logo_path,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const string unita): AbstractSensor(name,descrizione,logo_path,ID),
                                        capacity(capacity),
                                        dati(dati),
                                        currentLevel(currentLevel),
                                        unita(unita) {}
                     
const double LevelSensor:: getCapacity()const {
    return capacity;
}

LevelSensor& LevelSensor:: setCapacity(double capacity){
    this->capacity;
    return *this;
}

const vector<double> LevelSensor::getDati()const {
    return dati;
}

const double LevelSensor::getCurrentlevel()const {
    return currentLevel;
}

const string LevelSensor::getUnita()const {
    return unita;
}

LevelSensor& LevelSensor::setUnita(string unita) {
    this->unita;
    return *this;
}