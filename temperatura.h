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
                    const string ID,
                    const vector<double> dati,
                    const double valoreCorrente,
                    const string unita,
                    const double Tmin,
                    const double Tmax);
        string stato(double valoreCorrente)const ;

};

#endif // TEMPERATURA_H
