#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include <string>

#include "IVisitor.h"
#include "sconstvisitor.h"

using namespace std;
namespace Sensor{


class AbstractSensor {
    private:
        string name;
        string description;
        unsigned int ID;

    public:
        AbstractSensor(const string name,
                       const string description,
                       const unsigned int ID);
        virtual ~AbstractSensor();
        const string& getName() const;
        AbstractSensor& setName(const string name);
        const string& getDescription()const;
        AbstractSensor& setDescription(const string description);
        unsigned int getID() const;
        virtual void accept(IVisitor& visitor) = 0;
        virtual void accept(SConstVisitor& visitor) const = 0;

};
}

#endif // ABSTRACTSENSOR_H
