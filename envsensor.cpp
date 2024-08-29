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

    if(!dati.empty())
        return dati.back();
    else
        return 0;
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
    if(!dati.empty()){
        double min = dati[0];

        for (int i=0; i<n; i++){
            if (dati[i]<min)
                min = dati[i];
        }
        return min;
    }
    else return 0;


    
}

double EnvSensor::valoreMax()const {

    int n = dati.size();
    if(!dati.empty()){
        double max = dati[0];

        for (int i=0; i<n; i++){
            if (dati[i]>max)
                max = dati[i];
        }

        return max;
    }
    else
        return 0;

}
