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
                const string descrizione,
                const string logo_path,
                const string ID,
                const vector<double> dati,
                const double valoreCorrente,
                const string unita,
                const double soglioUmidita);
        string statoUmidita(double valoreCorrente)const ;
};

#endif // UMIDITA_H
