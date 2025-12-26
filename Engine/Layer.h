#pragma once

#include <memory>

namespace Engine_Core
{

    class Layer
    {
        public:
            virtual ~Layer() = default;

            //virtual void OnEvent(Event& event) {}

            virtual void OnUpdate(float ts) {}

            virtual void OnRender() {}

            template <typename T, typename... Args>
            void TransitionTo(Args&&... args)
            {
                QueueTransition(std::move(std::make_unique<T>(std::forward<Args>(args)...)));
		    }
		private:
		    void QueueTransition(std::unique_ptr<Layer> toLayer);
    };
}
