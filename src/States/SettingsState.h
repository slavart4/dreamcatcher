#ifndef DREAMCATCHER_SETTINGSSTATE_H
#define DREAMCATCHER_SETTINGSSTATE_H

#include "State.h"
#include "../Game.h"

class SettingsState : public State {
public:
    SettingsState(Scene& scene) : m_scene(scene) {}
    void upKeyAction() override {}
    void downKeyAction() override {}
    void enterKeyAction() override {}
private:
    Scene& m_scene;
};


#endif //DREAMCATCHER_SETTINGSSTATE_H
