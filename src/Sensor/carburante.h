#ifndef CARBURANTE_H
#define CARBURANTE_H

#include <string>
#include <vector>

#include "levelsensor.h"

namespace Sensor{

class Carburante: public LevelSensor {
    private:
        double soglia;

    public:
        Carburante(const std::string name,
                    const std::string description,
                    const unsigned int ID,
                    const double capacity,
                    const double soglia,
                    const std::vector<double> dati = {0,0,0,0,0,0,0}
                    );
        const double& getSoglia() const;
        AbstractSensor& setSoglia(const double soglia);
        double flusso(std::vector<double> dati)const;
        std::string statoQuantita(double currentLevel)const;
        void accept(SVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;

};

}

#endif // CARBURANTE_H
