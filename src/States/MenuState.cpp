#include "MenuState.h"

void MenuState::upKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->decreaseChosen();
}

void MenuState::downKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->increaseChosen();
}

void MenuState::enterKeyAction() {
    m_sceneId = m_scenesManager.scene(m_sceneId)->options()->action();
}