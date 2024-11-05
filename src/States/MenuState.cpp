#include "MenuState.h"
#include "StoryState.h"

void MenuState::upKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->decreaseChosen();
}

void MenuState::downKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->increaseChosen();
}

actionParams& MenuState::enterKeyAction() {
    actionParams params = m_scenesManager.scene(m_sceneId)->options()->action();
    if(params.toScene > 0) {
        if(m_scenesManager.scene(params.toScene)->type() == STORY_SCENE) {
            m_stateContext.setState(std::make_shared<StoryState>(m_stateContext, m_scenesManager, params.toScene));
        }
    }
    return m_scenesManager.scene(m_sceneId)->options()->action();
}