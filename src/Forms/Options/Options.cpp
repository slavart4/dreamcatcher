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
        if(m_buttons[m_chosenButton + 1].visible()) {
            setChosen(m_chosenButton,false);
            ++m_chosenButton;
            setChosen(m_chosenButton,true);
        }
    }
}

void Options::decreaseChosen() {
    if(m_chosenButton > 0) {
        if(m_buttons[m_chosenButton - 1].visible()) {
            setChosen(m_chosenButton,false);
            --m_chosenButton;
            setChosen(m_chosenButton,true);
        }
    }
}


void Options::reverseVisible() {
    for(auto& button : m_buttons) {
        bool visible = button.visible();
        if(visible) {
            button.setChosen(false);
        }
        button.setVisible(!visible);
    }
    for(size_t button = 0; button <= size(); button++) {
        if(m_buttons[button].visible()) {
            m_buttons[button].setChosen(true);
            m_chosenButton = button;
            return;
        }
    }
}

std::string Options::buttonsText() {
    std::string result;
    for(auto& button : m_buttons) {
        if(button.visible()) result += (button.chosen() ? "\033[32m" : "") + button.text() + "\033[0m" + "\n";
    }
    return result;
}

actionParams& Options::action() {
    return m_buttons[m_chosenButton].action();
}

uint8_t Options::size() {
    return m_buttons.size();
}

uint8_t Options::chosen() {
    return m_chosenButton;
}


