#ifndef SREPOSITORY_H
#define SREPOSITORY_H

#include <vector>

#include "abstractsensor.h"

class SRepository {
public:
    virtual SRepository& create(AbstractSensor* sensor) = 0;
    virtual AbstractSensor* read(const unsigned int identifier) const = 0;
    virtual SRepository& update(AbstractSensor* sensor) = 0;
    virtual SRepository& remove(const unsigned int identifier) = 0;
    virtual std::vector<AbstractSensor*> readAll() const = 0;
    virtual ~SRepository() = default;
};


#endif // SREPOSITORY_H
