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
            const string description,
            const string ID,
            const vector<double> dati,
            const double valoreCorrente,
            const double pressioneAtmos);
            
        vector<double> pressioneAssoluta(vector<double> dati)const ;
        void accept(IVisitor& visitor) override;
};

#endif // PRESSIONE_H
