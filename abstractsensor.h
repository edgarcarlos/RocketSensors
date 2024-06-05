#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include <string>

using namespace std;

class AbstractSensor {
    private:
        string name;
        string description;
        string ID;

    public:
        AbstractSensor(const string name,
                       const string description,
                       const string ID);
        virtual ~AbstractSensor();
        const string& getName() const;
        AbstractSensor& setName(const string name);
        const string& getDescription()const;
        AbstractSensor& setDescription(const string description);
        const string& getID()const ;
        AbstractSensor& setID(const string ID);


};

#endif // ABSTRACTSENSOR_H
