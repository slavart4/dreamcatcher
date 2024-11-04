#include "Options.h"

Button &Options::button(uint8_t index) {
    return m_buttons[index];
}

void Options::addButton(const Button& button) {
    m_buttons.push_back(button);
    if(button.chosen()) { m_defaultChosen = size() - 1; }
}

void Options::setChosen(uint8_t index, bool isChosen) {
    if(isChosen) m_chosenButton = index;
    m_buttons[index].setChosen(isChosen);
}

void Options::increaseChosen() {
    if(m_chosenButton < size() - 1) {
        m_buttons[m_chosenButton].setChosen(false);
        ++m_chosenButton;
        m_buttons[m_chosenButton].setChosen(true);
    }
}

void Options::decreaseChosen() {
    if(m_chosenButton > 0) {
        m_buttons[m_chosenButton].setChosen(false);
        --m_chosenButton;
        m_buttons[m_chosenButton].setChosen(true);
    }
}

std::string Options::buttonsText() {
    std::string result;
    for(auto& button : m_buttons) {
        result += (button.chosen() ? "\033[32m" : "") + button.text() + "\033[0m" + "\n";
    }
    return result;
}

uint8_t Options::action() {
    return m_buttons[m_chosenButton].action();
}

uint8_t Options::size() {
    return m_buttons.size();
}

uint8_t Options::chosen() {
    return m_chosenButton;
}


