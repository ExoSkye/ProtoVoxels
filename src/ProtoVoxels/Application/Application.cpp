#include <ProtoVoxels/Application/Application.hpp>

namespace ProtoVoxels::Application
{
    Application::Application() : Application(1280, 720) {}

    Application::Application(int w, int h) : m_Window(w, h)
    {
        //this->m_Registy = entt::registry();
        auto vert_shader = Shaders::Shader<gl::GL_VERTEX_SHADER>("#version 330 core\n"
                                                                 "layout (location = 0) in vec3 aPos;\n"
                                                                 "layout (location = 1) in vec3 aColor;\n"
                                                                 "  \n"
                                                                 "out vec4 vertexColor;\n"
                                                                 "\n"
                                                                 "void main()\n"
                                                                 "{\n"
                                                                 "    gl_Position = vec4(aPos, 1.0);\n"
                                                                 "    vertexColor = vec4(aColor, 1.0);\n"
                                                                 "}", true);

        auto frag_shader = Shaders::Shader<gl::GL_FRAGMENT_SHADER>("#version 330 core\n"
                                                                   "out vec4 FragColor;\n"
                                                                   "  \n"
                                                                   "in vec4 vertexColor;\n"
                                                                   "\n"
                                                                   "void main()\n"
                                                                   "{\n"
                                                                   "    FragColor = vertexColor;\n"
                                                                   "} ", true);

        this->m_ShaderProgram = Shaders::ShaderProgram(vert_shader, frag_shader);
        this->m_ShaderProgram.use();
    }

    void Application::run()
    {

    }
}