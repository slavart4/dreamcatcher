#include "FightState.h"

FightState::FightState(StateContext &stateContext, ScenesManager &scenesManager, uint8_t sceneId) :
        m_stateContext(stateContext), m_scenesManager(scenesManager), m_sceneId(sceneId) {
    m_scenesManager.scene(m_sceneId)->setTitle(makeTitle());
}

void FightState::upKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->decreaseChosen();
}

void FightState::downKeyAction() {
    m_scenesManager.scene(m_sceneId)->options()->increaseChosen();
}

actionParams& FightState::enterKeyAction() {
    actionParams params = m_scenesManager.scene(m_sceneId)->options()->action();
    processEnterAction(params);
    return m_scenesManager.scene(m_sceneId)->options()->action();
}

void FightState::processEnterAction(actionParams &params) {
    if(params.attack >= 0) {
        processAttack();
    }
    if(params.specAbility >= 0) {
        CharactersManager::GetInstance()->mainCharacter()->specialAbility();
        m_scenesManager.scene(m_sceneId)->setTitle(makeTitle());
    }
}

std::string FightState::makeTitle() {
    std::shared_ptr<Character> main = CharactersManager::GetInstance()->mainCharacter();
    std::shared_ptr<Character> enemy = CharactersManager::GetInstance()->character(m_scenesManager.scene(m_sceneId)->enemy());

    std::string title = main->name() + "(" + std::to_string(main->hp()) + " hp)" +
            " vs "
            + enemy->name() + "(" + std::to_string(enemy->hp()) + " hp)";
    return title;
}

void FightState::processAttack() {
    uint8_t enemy = m_scenesManager.scene(m_sceneId)->enemy();
    AttackResult res = CharactersManager::GetInstance()->attack(enemy);
    if(res.finished) {
        if(res.winner == enemy) {
            onLose();
        } else {
            onWin();
        }
    } else {
        m_scenesManager.scene(m_sceneId)->setTitle(makeTitle());
    }
}

void FightState::onWin() {
    m_scenesManager.scene(m_sceneId)->setTitle("You won!");
}

void FightState::onLose() {
    m_scenesManager.scene(m_sceneId)->setTitle("You lose!");
}