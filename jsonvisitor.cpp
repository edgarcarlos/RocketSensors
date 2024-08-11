#include "jsonvisitor.h"

QJsonObject JsonVisitor::getObject() const {
    return object;
}

void JsonVisitor::visit(const Temperatura& temperatura) {

    QJsonObject temperaturaObject;

    temperaturaObject.insert("type", QJsonValue::fromVariant("temperatura"));
    temperaturaObject.insert("id", QJsonValue::fromVariant(temperatura.getID()));
    temperaturaObject.insert("name", QJsonValue::fromVariant(temperatura.getName().c_str()));
    temperaturaObject.insert("description", QJsonValue::fromVariant(temperatura.getDescription().c_str()));
    temperaturaObject.insert("Tmin", QJsonValue::fromVariant(temperatura.getTmin()));
    temperaturaObject.insert("Tmax", QJsonValue::fromVariant(temperatura.getTmax()));

    object = temperaturaObject;
}

void JsonVisitor::visit(const Pressione& pressione) {

    QJsonObject pressioneObject;

    pressioneObject.insert("type", QJsonValue::fromVariant("pressione"));
    pressioneObject.insert("id", QJsonValue::fromVariant(pressione.getID()));
    pressioneObject.insert("name", QJsonValue::fromVariant(pressione.getName().c_str()));
    pressioneObject.insert("description", QJsonValue::fromVariant(pressione.getDescription().c_str()));
    pressioneObject.insert("Pmax", QJsonValue::fromVariant(pressione.getPmax()));

    object = pressioneObject;
}

void JsonVisitor::visit(const Carburante& carburante) {

    QJsonObject carburanteObject;

    carburanteObject.insert("type", QJsonValue::fromVariant("carburante"));
    carburanteObject.insert("id", QJsonValue::fromVariant(carburante.getID()));
    carburanteObject.insert("name", QJsonValue::fromVariant(carburante.getName().c_str()));
    carburanteObject.insert("description", QJsonValue::fromVariant(carburante.getDescription().c_str()));
    carburanteObject.insert("capacity", QJsonValue::fromVariant(carburante.getCapacity()));
    carburanteObject.insert("Soglio", QJsonValue::fromVariant(carburante.getSoglio()));

    object = carburanteObject;
}

void JsonVisitor::visit(const PositionSensor& positionSensor) {

    QJsonObject positionSensorObject;

    positionSensorObject.insert("type", QJsonValue::fromVariant("positionSensor"));
    positionSensorObject.insert("id", QJsonValue::fromVariant(positionSensor.getID()));
    positionSensorObject.insert("name", QJsonValue::fromVariant(positionSensor.getName().c_str()));
    positionSensorObject.insert("description", QJsonValue::fromVariant(positionSensor.getDescription().c_str()));

    object = positionSensorObject;
}












