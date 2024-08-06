#include "pressione.h"

Pressione::Pressione(const string name,
            const string description,
            const string ID,
            const vector<double> dati,
            const double valoreCorrente,
            const double pressioneAtmos): EnvSensor(name,description,ID,dati,valoreCorrente),
                                            pressioneAtmos(pressioneAtmos) {}
            

vector<double> Pressione::pressioneAssoluta(vector<double> dati)const {

    vector<double> A;
    double pressioneA;

    for(unsigned int i = 0; i<dati.size(); i++){
        pressioneA = dati[i] + pressioneAtmos;
        A.push_back(pressioneA);
    }

    return A;
}

