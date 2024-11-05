#ifndef DREAMCATCHER_DOWNKEYCOMMAND_H
#define DREAMCATCHER_DOWNKEYCOMMAND_H

#include "../Command.h"

class DownKeyCommand : public Command {
public:
    void execute(StateContext& stateContext) override;
};


#endif //DREAMCATCHER_DOWNKEYCOMMAND_H
