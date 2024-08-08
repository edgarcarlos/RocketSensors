#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <string>
#include <vector>

#include "envsensor.h"

using namespace std;


class Temperatura: public EnvSensor {
    private:
        double Tmin;
        double Tmax;

    public:
        Temperatura(const string name,
                    const string description,
                    const unsigned int ID,
                    const vector<double> dati,
                    const double valoreCorrente,
                    const double Tmin,
                    const double Tmax);
        const double& getTmin() const;
        const double& getTmax() const;
        string stato(double valoreCorrente)const ;
        void accept(IVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;
};

#endif // TEMPERATURA_H
