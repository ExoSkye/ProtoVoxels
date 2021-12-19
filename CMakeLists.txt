cmake_minimum_required(VERSION 3.21)
project(ProtoVoxels)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(nall)
add_subdirectory(entt)

find_package(OpenGL REQUIRED)
find_package(glbinding REQUIRED)
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)

add_library(ProtoVoxels SHARED
        src/ProtoVoxels/Window/Window.cpp include/ProtoVoxels/Window/Window.hpp
        include/ProtoVoxels/Shaders/Shader.hpp
        src/ProtoVoxels/Application/Application.cpp include/ProtoVoxels/Application/Application.hpp
        src/ProtoVoxels/Shaders/ShaderProgram.cpp include/ProtoVoxels/Shaders/ShaderProgram.hpp
        src/ProtoVoxels/Logger/Logger.cpp include/ProtoVoxels/Logger/Logger.hpp
)

target_include_directories(ProtoVoxels PRIVATE
        include
        entt/single_include
)

add_executable(ProtoVoxelsTest WIN32
        src/main.cpp
)

target_link_libraries(ProtoVoxels PRIVATE glbinding::glbinding OpenGL::GL SDL2::SDL2 nall)
target_link_libraries(ProtoVoxelsTest PRIVATE ProtoVoxels nall)
target_include_directories(ProtoVoxelsTest PRIVATE include)