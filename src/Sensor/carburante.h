#ifndef CARBURANTE_H
#define CARBURANTE_H

#include <string>
#include <vector>

#include "levelsensor.h"

namespace Sensor{

class Carburante: public LevelSensor {
    private:
        double soglio;

    public:
        Carburante(const std::string name,
                    const std::string description,
                    const unsigned int ID,
                    const double capacity,
                    const double soglio,
                    const std::vector<double> dati = {0,0,0,0,0,0,0}
                    );
        const double& getSoglio() const;
        AbstractSensor& setSoglio(const double soglio);
        double debito(std::vector<double> dati)const;
        std::string statoQuantita(double currentLevel)const;
        void accept(SVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;

};

}

#endif // CARBURANTE_H
