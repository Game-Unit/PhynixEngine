#include "Application.h"
#include "Renderer.h"

#include <memory>
#include <raylib.h>

Engine_Core::Application::Application(const ApplicationSettings& settings)
{
    InitWindow(settings.width, settings.hight, settings.applicationName);
    SetTargetFPS(settings.targetFPS);

    Run();
}

Engine_Core::Application::~Application()
{
    CloseWindow();
}

void Engine_Core::Application::Run()
{
    while (!WindowShouldClose())
    {
        m_renderer->Render();
    }
}
