#include "levelsensor.h"

namespace Sensor{

LevelSensor::LevelSensor(const std::string name,
                    const std::string description,
                    const unsigned int ID,
                    const double capacity,
                    const std::vector<double> dati
                    ): AbstractSensor(name,description,ID),
                                        capacity(capacity),
                                        dati(dati) {}

                     
double LevelSensor:: getCapacity()const {
    return capacity;
}

LevelSensor& LevelSensor:: setCapacity(double capacity){
    this->capacity = capacity;
    return *this;
}

const std::vector<double> LevelSensor::getDati()const {
    return dati;
}

double LevelSensor::getCurrentlevel()const {
    if(!dati.empty())
        return dati.back();
    else
        return 0;
}

}
