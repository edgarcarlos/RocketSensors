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


    public:
        LevelSensor(const string name,
                    const string description,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel);
        double getCapacity()const ;
        LevelSensor& setCapacity(double capacity);
        const vector<double> getDati()const ;
        double getCurrentlevel()const ;
        void accept(IVisitor& visitor) override;
};

#endif // LEVELSENSOR_H
