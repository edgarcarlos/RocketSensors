#ifndef JSONFILE_H
#define JSONFILE_H

#include <string>
#include <vector>

#include "abstractsensor.h"
#include "json.h"

namespace DataMapper{

class JsonFile
{
private:
    std::string path;
    Json& converter;
public:
    JsonFile(const std::string& path, Json& converter);
    static JsonFile fromPath(const std::string& path);
    const std::string& getPath() const;
    JsonFile& setPath(const std::string& path);
    const Json& getConverter() const;
    JsonFile& store(const std::vector<AbstractSensor*> sensors);
    std::vector<AbstractSensor*> load();
};
}

#endif // JSONFILE_H
