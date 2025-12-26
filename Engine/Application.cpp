#include "Application.h"
#include "Renderer.h"

#include <memory>
#include <raylib.h>


Engine_Core::Application::Application(ApplicationSettings& settings): m_settings(settings)
{
    InitWindow(settings.width, settings.hight, settings.applicationName);
    SetTargetFPS(settings.targetFPS);

    m_renderer = std::make_unique<Renderer>(settings);

    m_settings.activeScene->Start();

    Update();
}

void Engine_Core::Application::Update()
{
    while (!WindowShouldClose())
    {
        m_renderer->Render();
    }
    CloseWindow();
}
