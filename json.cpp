#include "json.h"
#include "jsonvisitor.h"

Json::Json(SReader& reader): reader(reader) {}

const SReader& Json::getReader() const {
    return reader;
}

QJsonObject Json::fromObject(const AbstractSensor& sensor) {
    JsonVisitor json_visitor;
    sensor.accept(json_visitor);
    return json_visitor.getObject();
}

AbstractSensor* Json::toObject(const QJsonObject& json) const{
    return reader.read(json);
}
