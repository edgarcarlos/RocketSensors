#ifndef CARBURANTE_H
#define CARBURANTE_H

#include <string>
#include <vector>

#include "levelsensor.h"

using namespace std;

class Carburante: public LevelSensor {
    private:
        double soglio;

    public:
        Carburante(const string name,
                    const string description,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const string unita,
                    const double soglio);
        double debito(vector<double> dati)const;
        string statoQuantita(double currentLevel)const;
};

#endif // CARBURANTE_H
