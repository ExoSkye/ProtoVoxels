#include "include/ProtoVoxels/window/Window.hpp"

namespace ProtoVoxel {
    Window::Window(int w, int h) {
        SDL_Init(SDL_INIT_VIDEO);

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        this->m_Window = SDL_CreateWindow("VoxelShit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h,
                                              SDL_WINDOW_OPENGL);
        this->m_Gl_ctx = SDL_GL_CreateContext(this->m_Window);

    }
    Window& Window::resize(int w, int h) {
        SDL_SetWindowSize(this->m_Window, w, h);
        return *this;
    }
    Window& Window::makeCurrent() {
        SDL_GL_MakeCurrent(this->m_Window, this->m_Gl_ctx);
        return *this;
    }
}