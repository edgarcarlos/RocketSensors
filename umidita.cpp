#include "umidita.h"

Umidita::Umidita(const string name,
                const string description,
                const unsigned int ID,
                const vector<double> dati,
                const double valoreCorrente,
                const double soglioUmidita): EnvSensor(name,description,ID,dati,valoreCorrente),
                                            soglioUmidita(soglioUmidita) {}

string Umidita::statoUmidita(double valoreCorrente)const {

    if(valoreCorrente <= soglioUmidita)
        return string("Basso");
        
    else return string("Sufficiente");
}

