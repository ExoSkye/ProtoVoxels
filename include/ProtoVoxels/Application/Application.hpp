#pragma once

//#include <entt/entt.hpp>

#include <ProtoVoxels/Window/Window.hpp>
#include <ProtoVoxels/Logger/Logger.hpp>
#include <ProtoVoxels/Shaders/Shader.hpp>
#include <ProtoVoxels/Shaders/ShaderProgram.hpp>

using namespace ProtoVoxels;
using namespace ProtoVoxels::Logger;

namespace ProtoVoxels::Application
{

    class Application
    {
    public:
        Application();
        Application(int w, int h);
        void run();
    private:
        //entt::registry m_Registy;
        Window::Window m_Window;
        Shaders::ShaderProgram m_ShaderProgram;
    };

}