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
        AbstractSensor(const string name,
                       const string descrizione,
                       const string logo_path,
                       const string ID);
        virtual ~AbstractSensor();
        const string& getName() const;
        AbstractSensor& setName(const string name);
        const string& getDescrizione()const;
        AbstractSensor& setDescrizione(const string descrizione);
        const string& getLogo()const ;
        const string& getID()const ;
        AbstractSensor& setID(const string ID);


};

#endif // ABSTRACTSENSOR_H
