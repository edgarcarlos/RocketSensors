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
        Ossigeno(const string name,
                    const string description,
                    const string ID,
                    const double capacity,
                    const vector<double> dati,
                    const double currentLevel,
                    const string unita,
                    const bool qualita,
                    const double soglio);
        bool isQualita()const ;
        string statoQuantita(double currentLevel)const ;
};

#endif // OSSIGENO_H
