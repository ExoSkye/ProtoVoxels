#include <cstdio>
#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <SDL2/SDL.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    SDL_Init(SDL_INIT_VIDEO);

    glbinding::initialize([](const char * name) { return (glbinding::ProcAddress)SDL_GL_GetProcAddress(name); }, false);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_Window* window = SDL_CreateWindow("VoxelShit", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);

    FILE* frag_file = fopen("frag.glsl", "r");
    fseek(frag_file, 0, SEEK_END);
    int frag_len = ftell(frag_file);
    fseek(frag_file, 0, SEEK_SET);
    std::string frag_str;
    frag_str.resize(frag_len, '\0');
    fread(frag_str.data(), 1, frag_len, frag_file);

    gl::GLuint frag_shader = gl::glCreateShader(gl::GL_FRAGMENT_SHADER);

    const char* frag_c_str = frag_str.c_str();

    gl::glShaderSource(frag_shader, 1, &frag_c_str, NULL);
    gl::glCompileShader(frag_shader);

    FILE* vert_file = fopen("vert.glsl", "r");
    fseek(vert_file, 0, SEEK_END);
    int vert_len = ftell(vert_file);
    fseek(vert_file, 0, SEEK_SET);
    std::string vert_str;
    frag_str.resize(vert_len, '\0');
    fread(&vert_str[0], vert_len, 1, vert_file);

    gl::GLuint vert_shader = gl::glCreateShader(gl::GL_VERTEX_SHADER);

    const char* vert_c_str = vert_str.c_str();

    gl::glShaderSource(vert_shader, 1, &vert_c_str, NULL);
    gl::glCompileShader(vert_shader);

    gl::GLuint shader_program = gl::glCreateProgram();

    gl::glAttachShader(shader_program, vert_shader);
    gl::glAttachShader(shader_program, frag_shader);
    gl::glLinkProgram(shader_program);

    gl::glUseProgram(shader_program);



    return 0;
}
