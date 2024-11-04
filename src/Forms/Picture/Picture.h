#ifndef DREAMCATCHER_PICTURE_H
#define DREAMCATCHER_PICTURE_H

#include <iostream>
#include <cstdint>
#include <fstream>

class Picture {
public:
    Picture(const std::string& path);
    size_t high() const { return m_high; }
    std::string& pictureText() { return m_picture; }
private:
    std::string m_path;
    std::string m_picture;
    size_t m_high = 0;
};


#endif //DREAMCATCHER_PICTURE_H
