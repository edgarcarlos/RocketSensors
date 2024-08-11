#ifndef READER_H
#define READER_H

#include <map>
#include <QJsonObject>
#include "SReader.h"
#include "json.h"

class Reader: public SReader
{
private:
    std::map<unsigned int, AbstractSensor*> cache;
public:
    const std::map<unsigned int, AbstractSensor*>& getCache() const;
    Reader& clear();
    AbstractSensor* read(const QJsonObject& object) override;

private:
    static Temperatura* readTemperatura(const QJsonObject& object) ;
    static Pressione* readPressione(const QJsonObject& object) ;
    static Carburante* readCarburante(const QJsonObject& object) ;
    static PositionSensor* readPositionSensor(const QJsonObject& object) ;

};

#endif // READER_H
