#pragma once

#include <SDL2/SDL.h>

namespace ProtoVoxels::Window
{
    class Window
    {
    public:
        Window() = delete;
        Window(int w, int h);
        Window& resize(int w, int h);
        Window& makeCurrent();
    private:
        SDL_Window *m_Window;
        SDL_GLContext m_Gl_ctx;
    };

}

