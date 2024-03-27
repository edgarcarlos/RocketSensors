#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include <string>

using namespace std;

class AbstractSensor {
    private:
        string name;
        string descrizione;
        string logo_path;
        string ID;

    public:
        AbstractSensor(string name,
                       string descrizione,
                       string logo_path,
                       string ID);
        virtual ~AbstractSensor();
        string& getName();
        AbstractSensor& setName(string name);
        string& getDescrizione();
        AbstractSensor& setDescrizione(string descrizione);
        string& getLogo();
        string& getID();
        AbstractSensor& setID(string ID);


};

#endif // ABSTRACTSENSOR_H
