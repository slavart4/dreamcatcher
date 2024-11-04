#include "Renderer.h"

void Renderer::draw(Scene &scene) {
    clear();
    std::cout << scene.picture()->pictureText() << std::endl;
    std::cout << scene.text() << std::endl;
    std::cout << scene.options()->buttonsText() << std::endl;
}

void Renderer::clear() {
    system("cls");
}

void Renderer::grawPicture(Scene &scene) {

}

void Renderer::grawText(Scene &scene) {

}

void Renderer::grawOptions(Scene &scene) {

}
