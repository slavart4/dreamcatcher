#include "Renderer.h"

Renderer* Renderer::renderer_singleton_= nullptr;
Renderer* Renderer::GetInstance()
{
    if(renderer_singleton_==nullptr){
        renderer_singleton_ = new Renderer();
    }
    return renderer_singleton_;
}

Renderer::Renderer() {
    for(int i = 0; i < m_windowWidth; i++) {
        m_separateLine += "_";
    }
}


void Renderer::draw(Scene &scene) {
    clear();
    drawPicture(scene);
    drawSeparateLine();
    drawTitle(scene);
    drawText(scene);
    drawSeparateLine();
    drawOptions(scene);
}

void Renderer::clear() {
    system("cls");
}

void Renderer::drawPicture(Scene &scene) {
    size_t diff = m_pictureSlot - scene.picture()->high();
    size_t space = (diff > 2) ? (diff / 2) : 0;

    fillEmpty(space);
    std::cout << scene.picture()->pictureText() << std::endl;
}

void Renderer::drawTitle(Scene &scene) {
    std::cout << scene.title() << "\n\n";
}

void Renderer::drawText(Scene &scene) {
    std::cout << scene.text() << std::endl;
}

void Renderer::drawOptions(Scene &scene) {
    std::cout << scene.options()->buttonsText();
}

void Renderer::drawSeparateLine() {
    std::cout << m_separateLine << std::endl;
}

void Renderer::fillEmpty(size_t high) {
    for(int i = 0; i < high; i++) {
        std::cout << std::endl;
    }
}
