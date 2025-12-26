#include "Renderer.h"
#include "Application.h"
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

Engine_Core::Renderer::Renderer(ApplicationSettings& settings) : m_settings(settings)
{
    rlImGuiSetup(true);
}

void Engine_Core::Renderer::Render()
{
    BeginDrawing();
    ClearBackground(m_settings.sceenColor);

    m_settings.activeScene->Update();

    rlImGuiBegin();

    m_settings.activeScene->RenderUI();

    rlImGuiEnd();

    EndDrawing();
}

Engine_Core::Renderer::~Renderer()
{
    rlImGuiShutdown();
}
