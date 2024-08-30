#ifndef SREADER_H
#define SREADER_H

#include <QJsonObject>

#include "../../abstractsensor.h"

namespace Sensor {
namespace Converter {
namespace Json {

class SReader {
public:
    virtual ~SReader() {};
    virtual AbstractSensor* read(const QJsonObject& object) = 0;
};

}
}
}

#endif // SREADER_H
