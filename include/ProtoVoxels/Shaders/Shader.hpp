#pragma once

#include <nall/string.hpp>
#include <nall/file.hpp>
#include <glbinding/gl/gl.h>
#include <ProtoVoxels/Logger/Logger.hpp>

using namespace ProtoVoxels::Logger;

namespace ProtoVoxels::Shaders {
    template <gl::GLenum T>
    class Shader {
    public:
        Shader() = delete;

        explicit Shader(const nall::string& source, bool inLine, bool compileNow = true) {
            if (!inLine)
            {
                log(nall::string("Creating shader from file:").append(source), LogLevel::DEBUG);
                this->m_fileName = source;
                auto fileHandle = nall::file::open(source, nall::file::mode::read);
                this->m_Source = fileHandle.reads(fileHandle.size());
            }
            else {
                log(nall::string("Creating shader from string"), LogLevel::DEBUG);
                this->m_fileName = "";

                this->m_Source = source;
            }

            if (compileNow) {
                compile();
            }
        }

        Shader& compile() {
            if (this->m_Compiled == -1) {
                log(nall::string("Compiling shader"), LogLevel::DEBUG);
                this->m_Compiled = gl::glCreateShader(this->m_Type);
                const char* source_c_str = this->m_Source.begin();
                auto length = (gl::GLint)this->m_Source.size();
                gl::glShaderSource(this->m_Compiled, 1, &source_c_str, &length);
                gl::glCompileShader(this->m_Compiled);
            }
            else {
                log(nall::string("Skipping compilation of shader since it is already compiled"), LogLevel::DEBUG);
            }

            return *this;
        }

        gl::GLuint getIndex() const {
            return this->m_Compiled;
        }

    private:
        nall::string m_fileName;
        nall::string m_Source;
        gl::GLenum m_Type = T;
        gl::GLuint m_Compiled = -1;
    };
}