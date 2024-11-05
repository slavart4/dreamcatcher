#ifndef DREAMCATCHER_OPTIONS_H
#define DREAMCATCHER_OPTIONS_H

#include "../Button/Button.h"

class Options {
public:
    Options() = default;
    Button& button(uint8_t index);
    void addButton(const Button& button);

    void setChosen(uint8_t index, bool isChosen);
    void increaseChosen();
    void decreaseChosen();

    actionParams& action();
    std::string buttonsText();
    uint8_t size();
    uint8_t chosen();
private:
    uint8_t m_chosenButton = 0;
    uint8_t m_defaultChosen = 0;
    std::vector<Button> m_buttons;
};


#endif //DREAMCATCHER_OPTIONS_H
