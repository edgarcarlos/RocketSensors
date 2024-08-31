#include "jsonvisitor.h"
#include <QJsonArray>

namespace Sensor {
namespace Converter {
namespace Json {

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

    QJsonArray datiArray;
    for (double dato : temperatura.getDati()) {
        datiArray.append(QJsonValue::fromVariant(dato));
    }
    temperaturaObject.insert("dati", datiArray);

    object = temperaturaObject;
}

void JsonVisitor::visit(const Pressione& pressione) {

    QJsonObject pressioneObject;

    pressioneObject.insert("type", QJsonValue::fromVariant("pressione"));
    pressioneObject.insert("id", QJsonValue::fromVariant(pressione.getID()));
    pressioneObject.insert("name", QJsonValue::fromVariant(pressione.getName().c_str()));
    pressioneObject.insert("description", QJsonValue::fromVariant(pressione.getDescription().c_str()));
    pressioneObject.insert("Pmax", QJsonValue::fromVariant(pressione.getPmax()));

    QJsonArray datiArray;
    for (double dato : pressione.getDati()) {
        datiArray.append(QJsonValue::fromVariant(dato));
    }
    pressioneObject.insert("dati", datiArray);

    object = pressioneObject;
}

void JsonVisitor::visit(const Carburante& carburante) {

    QJsonObject carburanteObject;

    carburanteObject.insert("type", QJsonValue::fromVariant("carburante"));
    carburanteObject.insert("id", QJsonValue::fromVariant(carburante.getID()));
    carburanteObject.insert("name", QJsonValue::fromVariant(carburante.getName().c_str()));
    carburanteObject.insert("description", QJsonValue::fromVariant(carburante.getDescription().c_str()));
    carburanteObject.insert("capacity", QJsonValue::fromVariant(carburante.getCapacity()));
    carburanteObject.insert("soglia", QJsonValue::fromVariant(carburante.getSoglia()));

    QJsonArray datiArray;
    for (double dato : carburante.getDati()) {
        datiArray.append(QJsonValue::fromVariant(dato));
    }
    carburanteObject.insert("dati", datiArray);

    object = carburanteObject;
}

void JsonVisitor::visit(const PositionSensor& positionSensor) {

    QJsonObject positionSensorObject;

    positionSensorObject.insert("type", QJsonValue::fromVariant("positionSensor"));
    positionSensorObject.insert("id", QJsonValue::fromVariant(positionSensor.getID()));
    positionSensorObject.insert("name", QJsonValue::fromVariant(positionSensor.getName().c_str()));
    positionSensorObject.insert("description", QJsonValue::fromVariant(positionSensor.getDescription().c_str()));

    QJsonArray datiArray;
    for (const auto& loc : positionSensor.getDati()) {
        QJsonObject locObject;
        locObject.insert("longitude", QJsonValue::fromVariant(loc.longitude));
        locObject.insert("latitude", QJsonValue::fromVariant(loc.latitude));
        locObject.insert("altitude", QJsonValue::fromVariant(loc.altitude));
        datiArray.append(locObject);
    }
    positionSensorObject.insert("dati", datiArray);

    object = positionSensorObject;
}


}
}
}









