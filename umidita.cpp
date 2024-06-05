#include "umidita.h"

Umidita::Umidita(const string name,
                const string description,
                const string ID,
                const vector<double> dati,
                const double valoreCorrente,
                const string unita,
                const double soglioUmidita): EnvSensor(name,description,type,ID,dati,valoreCorrente,unita),
                                            soglioUmidita(soglioUmidita) {}

string Umidita::statoUmidita(double valoreCorrente)const {

    if(valoreCorrente <= soglioUmidita)
        return string("Basso");
        
    else string("Sufficiente");
}

