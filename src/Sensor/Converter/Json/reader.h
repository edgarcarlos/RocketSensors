#ifndef READER_H
#define READER_H

#include <map>
#include <QJsonObject>
#include "SReader.h"

namespace Sensor {
namespace Converter {
namespace Json {

class Reader: public SReader
{
private:
    std::map<unsigned int, AbstractSensor*> cache;
public:
    const std::map<unsigned int, AbstractSensor*>& getCache() const;
    Reader& clear();
    AbstractSensor* read(const QJsonObject& object) override;

private:
    Temperatura* readTemperatura(const QJsonObject& object) const;
    Pressione* readPressione(const QJsonObject& object) const;
    Carburante* readCarburante(const QJsonObject& object) const;
    PositionSensor* readPositionSensor(const QJsonObject& object) const;

};

}
}
}

#endif // READER_H
