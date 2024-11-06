#ifndef DATAIO_H
#define DATAIO_H

#include <fstream>
#include <iostream>
#include <utility>

#include "nlohmann/json.hpp"

class DataIO {
public:
    DataIO(std::string  filePath) : m_filePath(std::move(filePath)) {};
    const nlohmann::json read();
    const void write(nlohmann::json data);
private:
    std::string m_filePath;
    nlohmann::json m_json;
};

#endif // DATAIO_H