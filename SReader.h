#ifndef SREADER_H
#define SREADER_H

#include <QJsonObject>

#include "abstractsensor.h"


class SReader {
public:
    virtual ~SReader() {};
    virtual AbstractSensor* read(const QJsonObject& object) = 0;
};

#endif // SREADER_H
