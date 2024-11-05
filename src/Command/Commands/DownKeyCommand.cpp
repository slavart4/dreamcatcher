#include "DownKeyCommand.h"
#include "../../States/StateContext.h"

void DownKeyCommand::execute(StateContext& stateContext) {
    stateContext.state()->downKeyAction();
    Renderer::GetInstance()->draw(stateContext.state()->scene());
}
