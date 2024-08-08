#include "envsensor.h"

EnvSensor::EnvSensor(const string name,
                    const string description,
                    const unsigned int ID,
                    const vector<double> dati,
                    const double valoreCorrente): AbstractSensor(name,description,ID),
                                                    dati(dati), valoreCorrente(valoreCorrente) {}

 const vector<double> EnvSensor::getDati()const {
    return dati;
 }

double EnvSensor::getValoreCorrente()const {
    return valoreCorrente;
}


double EnvSensor::media()const {

    int n = dati.size();
    double somma=0;

    for (int i=0; i<n; i++){
        somma += dati[i];
    }

    return somma/n;
}

double EnvSensor:: valoreMin()const {

    int n = dati.size();
    double min = dati[0];
    
    for (int i=0; i<n; i++){
        if (dati[i]<min)
            min = dati[i+1];
    }

    return min;
    
}

double EnvSensor::valoreMax()const {

    int n = dati.size();
    double max = dati[0];
    
    for (int i=0; i<n; i++){
        if (dati[i]>max)
            max = dati[i+1];
    }

    return max;
}
