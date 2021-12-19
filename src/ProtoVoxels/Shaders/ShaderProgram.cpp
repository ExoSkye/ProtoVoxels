#include <ProtoVoxels/Shaders/ShaderProgram.hpp>

namespace ProtoVoxels::Shaders
{

    ShaderProgram::ShaderProgram(Shader<gl::GL_VERTEX_SHADER> vert_shader, Shader<gl::GL_FRAGMENT_SHADER>
        frag_shader, bool linkNow)
    {
        this->m_Program = gl::glCreateProgram();
        gl::glAttachShader(this->m_Program, vert_shader.getIndex());
        gl::glAttachShader(this->m_Program, frag_shader.getIndex());

        if (linkNow) {
            link();
        }
    }

    void ShaderProgram::use() const
    {
        gl::glUseProgram(this->m_Program);
    }

    ShaderProgram& ShaderProgram::link() {
        gl::glLinkProgram(this->m_Program);
        return *this;
    }
}