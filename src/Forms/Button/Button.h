#ifndef DREAMCATCHER_BUTTON_H
#define DREAMCATCHER_BUTTON_H

#include <iostream>
#include <cstdint>
#include <utility>
#include <vector>

class Button {
public:
    explicit Button(uint8_t toScene, uint8_t picture, const std::string& text, bool chosen) :
    m_toScene(toScene), m_picture(picture), m_text(text), m_chosen(chosen) {};

    std::string text()  { return m_text; }
    bool chosen() const { return m_chosen; }
    uint8_t toScene()   { return m_toScene; }
    uint8_t length()    { return m_length; }
    uint8_t width()     { return m_width; }
    uint8_t picture()   { return m_picture; }

    void setChosen(bool chosen) { m_chosen = chosen; }
    uint8_t action() { return m_toScene; }
private:
    std::string m_text;
    uint8_t m_picture = 0;
    uint8_t m_toScene = 0;
    bool m_chosen = false;

    uint8_t m_length;
    uint8_t m_width;
};


#endif //DREAMCATCHER_BUTTON_H
