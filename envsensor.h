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

    public:
        EnvSensor(const string name,
                    const string description,
                    const string ID,
                    const vector<double> dati,
                    const double valoreCorrente,
                    const string unita);
        const vector<double> getDati()const ;
        const double getValoreCorrente()const ;
        double media()const ;
        double valoreMin()const ;
        double valoreMax()const ;
        void accept(IVisitor& visitor) override;
};

#endif // ENVSENSOR_H
