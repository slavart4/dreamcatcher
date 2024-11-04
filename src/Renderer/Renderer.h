#ifndef DREAMCATCHER_RENDERER_H
#define DREAMCATCHER_RENDERER_H

#include "../Scenes/Scene.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Renderer {
public:
    Renderer();
    void draw(Scene& scene);
private:
    void clear();
    void drawPicture(Scene& scene);
    void drawTitle(Scene& scene);
    void drawText(Scene& scene);
    void drawOptions(Scene& scene);
    void drawSeparateLine();
    void fillEmpty(size_t high);

    const size_t m_windowWidth = 120;
    const size_t m_windowHigh = 30;

    const size_t m_pictureSlot = 22;
    const size_t m_textSlot = 2;
    const size_t m_optionsSlot = 6;
    std::string m_separateLine;
};


#endif //DREAMCATCHER_RENDERER_H
