#include "EnterKeyCommand.h"
#include "../../States/StateContext.h"

void EnterKeyCommand::execute(StateContext &stateContext) {
    actionParams params = stateContext.state()->enterKeyAction();
    if(params.toScene > 0) {
        stateContext.state()->setScene(params.toScene);
        Renderer::GetInstance()->draw(stateContext.state()->scene());
    }
}
