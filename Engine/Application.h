#pragma once

#include <memory>
#include <raylib.h>

#include "Renderer.h"
#include "Scene.h"
#include "Scenes/BaseScene.h"


namespace Engine_Core
{
    struct ApplicationSettings
    {
        const char* applicationName;
        int width;
        int hight;
        int targetFPS = GetMonitorRefreshRate(GetCurrentMonitor());
        Color sceenColor = WHITE;
        std::unique_ptr<Scene> activeScene = std::make_unique<BaseScene>();
    };

    class Application
    {
        public:
            Application(ApplicationSettings& settings);
        private:
            void Update();

            ApplicationSettings& m_settings;
            std::unique_ptr<Renderer> m_renderer;
    };
}
