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
        Umidita(string name,
                string descrizione,
                string logo_path,
                string ID,
                vector<double> dati,
                double valoreCorrente,
                string unita,
                double soglioUmidita);
        string statoUmidita(double valoreCorrente);
        double tassoCambiamento(vector<double> dati);
};

#endif // UMIDITA_H
