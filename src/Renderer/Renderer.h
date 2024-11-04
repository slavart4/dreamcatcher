#ifndef DREAMCATCHER_RENDERER_H
#define DREAMCATCHER_RENDERER_H

#include "../Scenes/Scene.h"

class Renderer {
public:
    void draw(Scene& scene);
private:
    void clear();
    void grawPicture(Scene& scene);
    void grawText(Scene& scene);
    void grawOptions(Scene& scene);

    const size_t m_windowWidth = 120;
    const size_t m_windowHigh = 30;

    const size_t m_pictureSlot = 60;
    const size_t m_textSlot = 30;
    const size_t m_optionsSlot = 30;
};


#endif //DREAMCATCHER_RENDERER_H
