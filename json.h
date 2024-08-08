#ifndef JSON_H
#define JSON_H

#include "SReader.h"
//#include "JsonVisitor.h"


class Json
{
private:
    SReader& reader;

public:
    explicit Json(SReader& reader);
    const SReader& getReader() const;
    static QJsonObject fromObject(const AbstractSensor& sensor);
    AbstractSensor* toObject(const QJsonObject& json) const;

};

#endif // JSON_H
