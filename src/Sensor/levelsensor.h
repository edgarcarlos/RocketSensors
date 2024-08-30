#ifndef LEVELSENSOR_H
#define LEVELSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

namespace Sensor{

class LevelSensor: public AbstractSensor {
    private:
        double capacity;
        std::vector<double> dati;

    public:
        LevelSensor(const std::string name,
                    const std::string description,
                    const unsigned int ID,
                    const double capacity,
                    const std::vector<double> dati
                    );
        double getCapacity()const ;
        LevelSensor& setCapacity(double capacity);
        const std::vector<double> getDati()const ;
        double getCurrentlevel()const ;
        //void accept(SVisitor& visitor) override;
        //void accept(SConstVisitor& visitor) const override;

};

}

#endif // LEVELSENSOR_H
