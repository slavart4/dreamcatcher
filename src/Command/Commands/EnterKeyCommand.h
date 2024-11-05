#ifndef DREAMCATCHER_ENTERKEYCOMMAND_H
#define DREAMCATCHER_ENTERKEYCOMMAND_H

#include "../Command.h"

class EnterKeyCommand : public Command {
public:
    void execute(StateContext& stateContext) override;
};


#endif //DREAMCATCHER_ENTERKEYCOMMAND_H
