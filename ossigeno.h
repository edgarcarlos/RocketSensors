#ifndef OSSIGENO_H
#define OSSIGENO_H

#include <string>
#include <vector>

#include "levelsensor.h"

using namespace std;



class Ossigeno: public LevelSensor {
    private:
        bool qualita;
        double soglio;

    public:
        Ossigeno(string name,
                    string descrizione,
                    string logo_path,
                    string ID,
                    double capacity,
                    vector<double> dati,
                    double currentLevel,
                    string unita,
                    bool qualita,
                    double soglio);
        bool isQualita();
        string statoQuantita(double currentLevel);
};

#endif // OSSIGENO_H
