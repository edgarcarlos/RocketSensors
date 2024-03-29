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
        Carburante(string name,
                    string descrizione,
                    string logo_path,
                    string ID,
                    double capacity,
                    vector<double> dati,
                    double currentLevel,
                    string unita,
                    double soglio);
        double debito(vector<double> dati);
        string statoQuantita(double currentLevel);
};

#endif // CARBURANTE_H
