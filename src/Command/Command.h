#ifndef DREAMCATCHER_COMMAND_H
#define DREAMCATCHER_COMMAND_H

#include "../Renderer/Renderer.h"

class StateContext;
class Command {
public:
    virtual ~Command() = default;
    virtual void execute(StateContext& stateContext) = 0;
};


#endif //DREAMCATCHER_COMMAND_H
