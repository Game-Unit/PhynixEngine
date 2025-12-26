#pragma once

#include <raylib.h>

namespace Engine_Core
{
    struct ApplicationSettings;

    class Renderer
    {
        public:
            Renderer(ApplicationSettings& settings);
            ~Renderer();

            void Render();

        private:

        ApplicationSettings& m_settings;
    };
}
