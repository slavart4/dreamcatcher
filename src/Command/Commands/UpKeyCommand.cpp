#include "UpKeyCommand.h"
#include "../../States/StateContext.h"

void UpKeyCommand::execute(StateContext& stateContext) {
    stateContext.state()->upKeyAction();
    Renderer::GetInstance()->draw(stateContext.state()->scene());
}
