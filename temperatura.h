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
        Temperatura(string name,
                    string descrizione,
                    string logo_path,
                    string ID,
                    vector<double> dati,
                    double valoreCorrente,
                    string unita,
                    double Tmin,
                    double Tmax);
        string stato(double valoreCorrente);

};

#endif // TEMPERATURA_H
