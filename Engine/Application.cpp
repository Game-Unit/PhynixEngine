#include "Application.h"

#include <memory>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

Engine_Core::Application::Application(const ApplicationSettings& settings)
{
    InitWindow(settings.width, settings.hight, settings.applicationName);
    rlImGuiSetup(true);
    SetTargetFPS(settings.targetFPS);
}

Engine_Core::Application::~Application()
{
    rlImGuiShutdown();
    CloseWindow();
}

void Engine_Core::Application::Run()
{
    while (!WindowShouldClose())
    {
        for (const std::unique_ptr<Layer>& layer : m_LayerStack)
            layer->OnUpdate(GetFrameTime());

        for (const std::unique_ptr<Layer>& layer : m_LayerStack)
            layer->OnRender();
    }
}
