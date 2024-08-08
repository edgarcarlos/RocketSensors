#ifndef JSONREPOSITORY_H
#define JSONREPOSITORY_H

#include <string>
#include <map>

#include "SRepository.h"
#include "jsonfile.h"


class JsonRepository: public SRepository
{
private:
    DataMapper::JsonFile data_mapper;
    std::map<unsigned int, AbstractSensor*> repository;

public:
    JsonRepository(DataMapper::JsonFile data_mapper);

    static JsonRepository fromPath(const std::string path);

    const DataMapper::JsonFile& getDataMapper() const;
    const std::map<unsigned int, AbstractSensor*>& getRepository() const;
    const std::string& getPath() const;
    JsonRepository& setPath(std::string path);
    JsonRepository& create(AbstractSensor* sensor) override;
    AbstractSensor* read(const unsigned int identifier) const override;
    JsonRepository& update(AbstractSensor* sensor) override;
    JsonRepository& remove(const unsigned int identifier) override;  // rimuove e dealloca
    JsonRepository& erase(const unsigned int identifier); // rimuove senza deallocare
    std::vector<AbstractSensor*> readAll() const override;
    JsonRepository& store();
    bool empty() const;
    ~JsonRepository() override;
};

#endif // JSONREPOSITORY_H
