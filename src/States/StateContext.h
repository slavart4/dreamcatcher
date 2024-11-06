#ifndef DREAMCATCHER_STATECONTEXT_H
#define DREAMCATCHER_STATECONTEXT_H

#include <memory>
#include "State.h"
#include "../Renderer/Renderer.h"

class StateContext {
public:
    void setState(std::shared_ptr<State> state) {
        m_state = std::move(state);
    }
    std::shared_ptr<State> state() {
        return m_state;
    }
private:
    std::shared_ptr<State> m_state;
};


#endif //DREAMCATCHER_STATECONTEXT_H
