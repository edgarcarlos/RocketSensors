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
        Pressione(const string name,
            const string descrizione,
            const string logo_path,
            const string ID,
            const vector<double> dati,
            const double valoreCorrente,
            const string unita,
            const double pressioneAtmos);
            
        vector<double> pressioneAssoluta(vector<double> dati)const ;
};

#endif // PRESSIONE_H
