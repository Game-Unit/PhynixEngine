#pragma once

#include <memory>
#include <type_traits>
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

            template<typename TLayer>
            requires(std::is_base_of_v<Layer, TLayer>)
            void PushLayer()
            {
                m_LayerStack.push_back(std::make_unique<TLayer>());
            }

            static Application& Get();
        private:
            std::vector<std::unique_ptr<Layer>> m_LayerStack;

            friend class Layer;
    };
}
