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
                    const unsigned int ID,
                    const double capacity,
                    const double soglio,
                   const vector<double> dati = {0,0,0,0,0,0,0},
                    const double currentLevel = 0.0);
        const double& getSoglio() const;
        AbstractSensor& setSoglio(const double soglio);
        double debito(vector<double> dati)const;
        string statoQuantita(double currentLevel)const;
        void accept(IVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;

};

#endif // CARBURANTE_H
