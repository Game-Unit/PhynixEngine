#include "Application.h"

#include <memory>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

static Engine_Core::Application* s_Application = nullptr;

Engine_Core::Application::Application(const ApplicationSettings& settings)
{
    s_Application = this;

    InitWindow(settings.width, settings.hight, settings.applicationName);
    rlImGuiSetup(true);
    SetTargetFPS(settings.targetFPS);
}

Engine_Core::Application::~Application()
{
    rlImGuiShutdown();
    CloseWindow();

    s_Application = nullptr;
}

void Engine_Core::Application::Run()
{
    while (!WindowShouldClose())
    {
        for (const std::unique_ptr<Layer>& layer : m_LayerStack)
            layer->OnUpdate(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);

        rlImGuiBegin();

        for (const std::unique_ptr<Layer>& layer : m_LayerStack)
            layer->OnRender();

        rlImGuiEnd();

        EndDrawing();

        Engine_Core::Layer::Transition();
    }
}

Engine_Core::Application& Engine_Core::Application::Get()
{
	assert(s_Application);
	return *s_Application;
}
