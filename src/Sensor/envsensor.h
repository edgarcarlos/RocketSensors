#ifndef ENVSENSOR_H
#define ENVSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

namespace Sensor{

class EnvSensor: public AbstractSensor {
    private:
        std::vector<double> dati;

    public:
        EnvSensor(const std::string name,
                const std::string description,
                const unsigned int ID,
                const std::vector<double> dati
                );
        const std::vector<double> getDati()const ;
        double getValoreCorrente()const ;
        double media()const ;
        double valoreMin()const ;
        double valoreMax()const ;
        //void accept(SVisitor& visitor) override;
        //void accept(SConstVisitor& visitor) const override;

};

}

#endif // ENVSENSOR_H
