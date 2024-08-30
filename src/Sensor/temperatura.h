#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <string>
#include <vector>

#include "envsensor.h"

using namespace std;
namespace Sensor{


class Temperatura: public EnvSensor {
    private:
        double Tmin;
        double Tmax;

    public:
        Temperatura(const string name,
                    const string description,
                    const unsigned int ID,
                    const double Tmin,
                    const double Tmax,
                    const vector<double> dati = {0,0,0,0,0,0,0,0,0},
                    const double valoreCorrente = 0.0);
        const double& getTmin() const;
        const double& getTmax() const;
        AbstractSensor& setTmin(const double Tmin);
        AbstractSensor& setTmax(const double Tmax);

        string stato(double valoreCorrente)const ;
        void accept(IVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;
};
}
#endif // TEMPERATURA_H
