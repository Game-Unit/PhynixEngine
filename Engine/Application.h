#pragma once

#include <memory>
#include <raylib.h>

#include "Renderer.h"


namespace Engine_Core
{
    struct ApplicationSettings
    {
        const char* applicationName;
        int width;
        int hight;
        int targetFPS = GetMonitorRefreshRate(GetCurrentMonitor());
        Color sceenColor = WHITE;
    };

    class Application
    {
        public:
            Application(const ApplicationSettings& settings = ApplicationSettings());
            ~Application();
        private:
            void Run();

            std::unique_ptr<Renderer> m_renderer;
    };
}
