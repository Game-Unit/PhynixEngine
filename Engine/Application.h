#pragma once

#include <memory>
#include <vector>
#include <raylib.h>

#include "Layer.h"


namespace Engine_Core
{
    struct ApplicationSettings
    {
        const char* applicationName;
        int width;
        int hight;
        int targetFPS = GetMonitorRefreshRate(GetCurrentMonitor());
    };

    class Application
    {
        public:
            Application(const ApplicationSettings& settings = ApplicationSettings());
            ~Application();

            void Run();
        private:
            std::vector<std::unique_ptr<Layer>> m_LayerStack;
    };
}
