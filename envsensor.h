#ifndef ENVSENSOR_H
#define ENVSENSOR_H

#include <string>
#include <vector>

#include "abstractsensor.h"

using namespace std;

class EnvSensor: public AbstractSensor {
    private:
        vector<double> dati;
        double valoreCorrente;
        string unita; 

    public:
        EnvSensor(string name,
                    string descrizione,
                    string logo_path,
                    string ID,
                    vector<double> dati,
                    double valoreCorrente,
                    string unita);
        vector<double> getDati();
        double getValoreCorrente();
        string getUnita();
        EnvSensor& setUnita(string unita);
        double media(vector<double> dati);
        double valoreMin(vector<double> dati);
        double valoreMax(vector<double> dati);
};

#endif // ENVSENSOR_H
