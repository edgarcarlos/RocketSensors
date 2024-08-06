#ifndef UMIDITA_H
#define UMIDITA_H

#include <string>
#include <vector>

#include "envsensor.h"


using namespace std;

class Umidita: public EnvSensor {
    private:
        double soglioUmidita;

    public:
        Umidita(const string name,
                const string description,
                const string ID,
                const vector<double> dati,
                const double valoreCorrente,
                const double soglioUmidita);
        string statoUmidita(double valoreCorrente)const ;
        void accept(IVisitor& visitor) override;
};

#endif // UMIDITA_H
