#ifndef DATAIO_H
#define DATAIO_H

#include <fstream>
#include <iostream>

#include "nlohmann/json.hpp"

class DataIO {
public:
    DataIO(const std::string& filePath) : m_filePath(filePath) { std::cout << "DataIO " << m_filePath << std::endl; };
    const nlohmann::json read();
    const void write(nlohmann::json data);
private:
    std::string m_filePath;
    nlohmann::json m_json;
};

#endif // DATAIO_H