#include "EnterKeyCommand.h"
#include "../../States/StateContext.h"

void EnterKeyCommand::execute(StateContext &stateContext) {
    stateContext.state()->enterKeyAction();
    Renderer::GetInstance()->draw(stateContext.state()->scene());
}
