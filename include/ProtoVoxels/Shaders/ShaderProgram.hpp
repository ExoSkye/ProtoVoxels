#pragma once

#include <ProtoVoxels/Shaders/Shader.hpp>
#include <glbinding/gl/gl.h>

namespace ProtoVoxels::Shaders
{
    class ShaderProgram {
    public:
        ShaderProgram() = delete;
        ShaderProgram(Shader<gl::GL_VERTEX_SHADER> vert_shader, Shader<gl::GL_FRAGMENT_SHADER> frag_shader,
                      bool linkNow = true);
        void use() const;
        ShaderProgram& link();

    private:
        gl::GLuint m_Program;
    };
}