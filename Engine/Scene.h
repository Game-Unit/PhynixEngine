#pragma once

namespace Engine_Core
{
    class Scene
    {
        public:
            virtual void Start() = 0;

            virtual void Update() = 0;
            virtual void RenderUI() = 0;

            virtual ~Scene() = default;
        private:
    };
}
