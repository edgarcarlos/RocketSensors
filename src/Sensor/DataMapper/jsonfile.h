#ifndef JSONFILE_H
#define JSONFILE_H

#include <string>
#include <vector>

#include "../abstractsensor.h"
#include "../Converter/Json/json.h"

namespace Sensor{
namespace DataMapper{

class JsonFile
{
private:
    std::string path;
    Converter::Json::Json& converter;
public:
    JsonFile(const std::string& path, Converter::Json::Json& converter);
    static JsonFile fromPath(const std::string& path);
    const std::string& getPath() const;
    JsonFile& setPath(const std::string& path);
    const Converter::Json::Json& getConverter() const;
    JsonFile& store(const std::vector<AbstractSensor*> sensors);
    std::vector<AbstractSensor*> load();
};
}
}
#endif // JSONFILE_H
