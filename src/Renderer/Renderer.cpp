#include "Renderer.h"


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
    drawOptions(scene);
}

void Renderer::clear() {
    system("cls");
}

void Renderer::drawPicture(Scene &scene) {
    size_t space = (m_pictureSlot - scene.picture()->high()) / 2;

    fillEmpty(space);
    std::cout << scene.picture()->pictureText() << std::endl;
    fillEmpty(space);
}

void Renderer::drawTitle(Scene &scene) {
    std::cout << CYAN << scene.title() << RESET << "\n"<< std::endl;
}

void Renderer::drawText(Scene &scene) {
    std::cout << scene.text() << std::endl;
}

void Renderer::drawOptions(Scene &scene) {
    std::cout << scene.options()->buttonsText() << std::endl;
}

void Renderer::drawSeparateLine() {
    std::cout << m_separateLine << std::endl;
}

void Renderer::fillEmpty(size_t high) {
    for(int i = 0; i < high; i++) {
        std::cout << std::endl;
    }
}
