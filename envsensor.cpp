#include "envsensor.h"

EnvSensor::EnvSensor(const string name,
                    const string description,
                    const string ID,
                    const vector<double> dati,
                    const double valoreCorrente,
                    const string unita): AbstractSensor(name,description,ID),
                                        dati(dati) {}

 const vector<double> EnvSensor::getDati()const {
    return dati;
 }

const double EnvSensor::getValoreCorrente()const {
    return valoreCorrente;
}

const string EnvSensor::getUnita()const {
    return unita;
}

EnvSensor& EnvSensor::setUnita(string unita){
    this->unita;
    return *this;
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
