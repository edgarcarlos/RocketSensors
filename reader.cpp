#include "reader.h"

#include "carburante.h"
#include "temperatura.h"
#include "pressione.h"
#include "positionsensor.h"

#include <QJsonArray>



const std::map<unsigned int, AbstractSensor*>& Reader::getCache() const{
    return cache;
}

Reader& Reader::clear() {
    cache.clear();
    return *this;
}

AbstractSensor* Reader::read(const QJsonObject& object) {
    QJsonValue type = object.value("type");
    if (type.isUndefined()) {
        throw std::invalid_argument("Missing sensor type.");
    }

    const unsigned int identifier = object.value("id").toInt();

    if (cache.count(identifier) > 0) {
        return cache[identifier];
    }

    else if (type.toString().compare("temperatura") == 0) {
        cache[identifier] = readTemperatura(object);
    }
    else if (type.toString().compare("pressione") == 0) {
        cache[identifier] = readPressione(object);
    }
    else if (type.toString().compare("carburante") == 0) {
        cache[identifier] = readCarburante(object);
    }
    else if (type.toString().compare("positionSensor") == 0) {
        cache[identifier] = readPositionSensor(object);
    }
    else {
        throw std::invalid_argument("Unknown sensor type.");
    }

    return cache[identifier];
}


Temperatura* Reader::readTemperatura(const QJsonObject& object) const {
    QJsonArray datiArray = object.value("dati").toArray();
    vector<double> dati;
    for (const QJsonValue& value : datiArray) {
        dati.push_back(value.toDouble());
    }

    return new Temperatura(
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("id").toInt(),
        object.value("Tmin").toDouble(),
        object.value("Tmax").toDouble(),
        dati
    );
}

Pressione* Reader::readPressione(const QJsonObject& object) const {
    QJsonArray datiArray = object.value("dati").toArray();
    vector<double> dati;
    for (const QJsonValue& value : datiArray) {
        dati.push_back(value.toDouble());
    }

    return new Pressione(
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("id").toInt(),
        object.value("Pmax").toDouble(),
        dati
    );
}

Carburante* Reader::readCarburante(const QJsonObject& object) const {
    QJsonArray datiArray = object.value("dati").toArray();
    vector<double> dati;
    for (const QJsonValue& value : datiArray) {
        dati.push_back(value.toDouble());
    }

    return new Carburante(
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("id").toInt(),
        object.value("capacity").toDouble(),
        object.value("soglio").toDouble(),
        dati
    );
}

PositionSensor* Reader::readPositionSensor(const QJsonObject& object) const {
    QJsonArray datiArray = object.value("dati").toArray();
    vector<PositionSensor::Localisation> dati;
    for (const QJsonValue& value : datiArray) {
        QJsonObject locObj = value.toObject();
        PositionSensor::Localisation loc{
            locObj.value("longitude").toDouble(),
            locObj.value("latitude").toDouble(),
            locObj.value("altitude").toDouble()
        };
        dati.push_back(loc);
    }
    return new PositionSensor(
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("id").toInt(),
        dati
    );
}
















