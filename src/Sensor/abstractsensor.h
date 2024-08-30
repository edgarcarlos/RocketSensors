#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include <string>

#include "svisitor.h"
#include "sconstvisitor.h"


namespace Sensor{


class AbstractSensor {
    private:
        std::string name;
        std::string description;
        unsigned int ID;

    public:
        AbstractSensor(const std::string name,
                       const std::string description,
                       const unsigned int ID);
        virtual ~AbstractSensor();
        const std::string& getName() const;
        AbstractSensor& setName(const std::string name);
        const std::string& getDescription()const;
        AbstractSensor& setDescription(const std::string description);
        unsigned int getID() const;
        virtual void accept(SVisitor& visitor) = 0;
        virtual void accept(SConstVisitor& visitor) const = 0;

};

}

#endif // ABSTRACTSENSOR_H
