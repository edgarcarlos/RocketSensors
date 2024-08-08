#include "levelsensor.h"

LevelSensor::LevelSensor(const string name,
                    const string description,
                    const unsigned int ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel): AbstractSensor(name,description,ID),
                                        capacity(capacity),
                                        dati(dati),
                                        currentLevel(currentLevel) {}
                     
double LevelSensor:: getCapacity()const {
    return capacity;
}

LevelSensor& LevelSensor:: setCapacity(double capacity){
    this->capacity = capacity;
    return *this;
}

const vector<double> LevelSensor::getDati()const {
    return dati;
}

double LevelSensor::getCurrentlevel()const {
    return currentLevel;
}


