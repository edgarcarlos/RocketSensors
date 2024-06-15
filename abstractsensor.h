#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include <string>

#include "IVisitor.h"

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
        virtual void accept(IVisitor& visitor) = 0;


};

#endif // ABSTRACTSENSOR_H
