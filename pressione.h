#ifndef PRESSIONE_H
#define PRESSIONE_H

#include <string>
#include <vector>

#include "envsensor.h"

using namespace std;

class Pressione: public EnvSensor {
    private:
        double pressioneAtmos;
    public:
        Pressione(string name,
            string descrizione,
            string logo_path,
            string ID,
            vector<double> dati,
            double valoreCorrente,
            string unita,
            double pressioneAtmos);
        vector<double> pressioneAtmos(vector<double> dati);
};

#endif // PRESSIONE_H
