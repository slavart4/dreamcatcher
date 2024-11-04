#include "DataIO.h"

const nlohmann::json DataIO::read() {
    std::ifstream ifs(m_filePath);
    if(!ifs.is_open()) throw std::ios_base::failure("Cannot open file " + m_filePath);

    try {
        m_json = nlohmann::json::parse(ifs);
    } catch (const nlohmann::json::parse_error& e) {
        std::cout << "DataIO read error" << std::endl;
        throw e;
    }
    return m_json;
}

const void DataIO::write(nlohmann::json data) {
    std::ofstream ofs(m_filePath);
    if(!ofs.is_open()) throw std::ios_base::failure("Cannot open file " + m_filePath);

    try {
        ofs << data.dump(4);
    } catch (const nlohmann::json::parse_error& e) {
        std::cout << "DataIO write error" << std::endl;
        throw e;
    }
}