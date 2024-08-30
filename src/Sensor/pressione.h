#ifndef PRESSIONE_H
#define PRESSIONE_H

#include <string>
#include <vector>

#include "envsensor.h"

namespace Sensor{

class Pressione: public EnvSensor {
    private:
        static double pressioneAtmos;
        double Pmax;
    public:
        Pressione(const std::string name,
            const std::string description,
            const unsigned int ID,
            const double Pmax,
            const std::vector<double> dati= {0,0,0,0,0,0,0}
            );

        const double& getPmax() const;
        AbstractSensor& setPmax(const double Pmax);
        std::vector<double> pressioneAssoluta(std::vector<double> dati)const ;
        void accept(SVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;

};

}
#endif // PRESSIONE_H
