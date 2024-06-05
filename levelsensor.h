#ifndef LEVELSENSOR_H
#define LEVELSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

using namespace std;


class LevelSensor: public AbstractSensor {
    private:
        double capacity;
        vector<double> dati;
        double currentLevel;
        string unita;

    public:
        LevelSensor(const string name,
                    const string description,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const string unita);
        const double getCapacity()const ;
        LevelSensor& setCapacity(double capacity);
        const vector<double> getDati()const ;
        const double getCurrentlevel()const ;
        const string getUnita()const ;
        LevelSensor& setUnita(string unita); 
};

#endif // LEVELSENSOR_H
