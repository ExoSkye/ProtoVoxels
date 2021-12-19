#include <cstdio>
#include <ProtoVoxels.hpp>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ProtoVoxels::Application::Application app(1280, 720);

    return 0;
}
