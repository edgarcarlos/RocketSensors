#ifndef PRESSIONE_H
#define PRESSIONE_H

#include <string>
#include <vector>

#include "envsensor.h"

using namespace std;

class Pressione: public EnvSensor {
    private:
        double pressioneAtmos;
        double Pmax;
    public:
        Pressione(const string name,
            const string description,
            const unsigned int ID,
            const vector<double> dati,
            const double valoreCorrente,
            const double pressioneAtmos,
            const double Pmax);

        const double& getPmax() const;
        vector<double> pressioneAssoluta(vector<double> dati)const ;
        void accept(IVisitor& visitor) override;
        void accept(SConstVisitor& visitor) const override;

};

#endif // PRESSIONE_H
