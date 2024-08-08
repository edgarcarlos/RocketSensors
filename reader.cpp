#include "reader.h"

#include "carburante.h"
#include "temperatura.h"
#include "pressione.h"
#include "positionsensor.h"



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


AbstractSensor* Reader::readTemperatura(const QJsonObject& object) {
    return new Temperatura(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("Tmin").toDouble(),
        object.value("Tmax").toDouble()
    );
}

AbstractSensor* Reader::readPressione(const QJsonObject& object) {
    return new Pressione(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("Pmax").toDouble()
    );
}

AbstractSensor* Reader::readCarburante(const QJsonObject& object) {
    return new Carburante(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString(),
        object.value("capacity").toDouble(),
        object.value("soglio").toDouble()
    );
}

AbstractSensor* Reader::readPositionSensor(const QJsonObject& object) {
    return new PositionSensor(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("description").toString().toStdString()
    );
}
















