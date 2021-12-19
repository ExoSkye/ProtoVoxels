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
        explicit Shader(const nall::string& fileName, bool compileNow = true) {
            log(nall::string("Creating shader from file:").append(fileName), LogLevel::DEBUG);
            this->m_fileName = fileName;
            this->m_fileHandle = nall::file::open(fileName, nall::file::mode::read);

            if (compileNow) {
                compile();
            }
        }

        Shader& compile() {
            if (this->m_Compiled == -1) {
                log(nall::string("Compiling shader: ").append(this->m_fileName), LogLevel::DEBUG);
                this->m_Compiled = gl::glCreateShader(this->m_Type);
                nall::string source = this->m_fileHandle.reads(this->m_fileHandle.size());
                const char* source_c_str = source.begin();
                u32 length = source.size();
                gl::glShaderSource(this->m_Compiled, 1, &source_c_str, &length);
                gl::glCompileShader(this->m_Compiled);
            }
            else {
                log(nall::string("Skipping compilation of ").append(this->m_fileName)
                        .append(nall::string(" since it is already compiled")), LogLevel::DEBUG);
            }

            return *this;
        }

        gl::GLuint getIndex() const {
            return this->m_Compiled;
        }

    private:
        nall::string m_fileName;
        nall::file_buffer m_fileHandle;
        gl::GLenum m_Type = T;
        gl::GLuint m_Compiled = -1;
    };
}