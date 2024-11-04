#include "Picture.h"

Picture::Picture(const std::string &path) : m_path(path) {
    std::ifstream inputFile(m_path);
    if (!inputFile.is_open()) {
        std::cerr << "Cannot open file " << m_path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        m_picture += line + "\n";
        ++m_high;
    }

    inputFile.close();
}
