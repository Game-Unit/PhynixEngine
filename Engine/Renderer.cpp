#include "Renderer.h"
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

Engine_Core::Renderer::Renderer()
{
    rlImGuiSetup(true);
}

void Engine_Core::Renderer::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);

    rlImGuiBegin();

    rlImGuiEnd();

    EndDrawing();
}

Engine_Core::Renderer::~Renderer()
{
    rlImGuiShutdown();
}
