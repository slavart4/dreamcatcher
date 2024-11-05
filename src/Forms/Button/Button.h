#ifndef DREAMCATCHER_BUTTON_H
#define DREAMCATCHER_BUTTON_H

#include <iostream>
#include <cstdint>
#include <utility>
#include <vector>
#include <memory>
//#include "../../Command/Command.h"

class Button {
public:
    explicit Button(uint8_t toSceneIndex, uint8_t textIndex, uint8_t pictureIndex, std::string  text, bool chosen) :
            m_toSceneIndex(toSceneIndex),
            m_textIndex(textIndex),
            m_pictureIndex(pictureIndex),
            m_text(std::move(text)),
            m_chosen(chosen) {};

    std::string text()       { return m_text; }
    bool chosen() const      { return m_chosen; }
    uint8_t length()         { return m_length; }
    uint8_t width()          { return m_width; }
    uint8_t pictureIndex()   { return m_pictureIndex; }
    uint8_t toSceneIndex()   { return m_toSceneIndex; }
    uint8_t textIndex()      { return m_textIndex; }

    void setChosen(bool chosen) { m_chosen = chosen; }
    uint8_t action() { return m_toSceneIndex; }

//    void setCommand(std::unique_ptr<Command>&& command);
//    void executeCommand();
private:
    std::string m_text;
    uint8_t m_pictureIndex = 0;
    uint8_t m_textIndex = 0;
    uint8_t m_toSceneIndex = 0;
    bool m_chosen = false;

    uint8_t m_length{};
    uint8_t m_width{};
};


#endif //DREAMCATCHER_BUTTON_H
