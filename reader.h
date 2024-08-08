#ifndef READER_H
#define READER_H

#include <map>
#include <QJsonObject>
#include "SReader.h"

class Reader: public SReader
{
private:
    std::map<unsigned int, AbstractSensor*> cache;
public:
    const std::map<unsigned int, AbstractSensor*>& getCache() const;
    Reader& clear();
    AbstractSensor* read(const QJsonObject& object) override;

private:
    static AbstractSensor* readTemperatura(const QJsonObject& object) ;
    static AbstractSensor* readPressione(const QJsonObject& object) ;
    static AbstractSensor* readCarburante(const QJsonObject& object) ;
    static AbstractSensor* readPositionSensor(const QJsonObject& object) ;

};

#endif // READER_H
