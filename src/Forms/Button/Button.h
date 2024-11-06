#ifndef DREAMCATCHER_BUTTON_H
#define DREAMCATCHER_BUTTON_H

#include <iostream>
#include <cstdint>
#include <utility>
#include <vector>
#include <memory>

struct actionParams {
    int8_t toScene = -1;
    int8_t setMainChar = -1;
    int8_t attack = -1;
    int8_t specAbility = -1;
    int8_t onWinScene = -1;
    int8_t onLoseScene = -1;
};

class Button {
public:
    explicit Button(actionParams params, uint8_t textIndex, uint8_t pictureIndex, std::string text, bool chosen, bool visible) :
            m_actionParams(params),
            m_textIndex(textIndex),
            m_pictureIndex(pictureIndex),
            m_text(std::move(text)),
            m_chosen(chosen),
            m_visible(visible) {};

    std::string text()           { return m_text; }
    bool chosen() const          { return m_chosen; }
    bool visible() const         { return m_visible; }

    uint8_t length() const       { return m_length; }
    uint8_t width() const        { return m_width; }
    uint8_t pictureIndex() const { return m_pictureIndex; }
    uint8_t textIndex() const    { return m_textIndex; }

    void setChosen(bool chosen) { m_chosen = chosen; }
    void setVisible(bool visible) { m_visible = visible; }
    actionParams& action() { return m_actionParams; };
private:
    std::string m_text;
    uint8_t m_pictureIndex = 0;
    uint8_t m_textIndex = 0;
    bool m_chosen = false;
    bool m_visible = true;
    actionParams m_actionParams;

    uint8_t m_length{};
    uint8_t m_width{};
};


#endif //DREAMCATCHER_BUTTON_H
