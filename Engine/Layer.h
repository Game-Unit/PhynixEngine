#pragma once

#include <memory>
#include <vector>

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

			static void Transition();

		private:

            struct Transitions
            {
                Layer& originalLayer;
                Layer& transitionLayer;

                Transitions(Layer& original, Layer& transition)
                        : originalLayer(original), transitionLayer(transition) {}
            };

		    void QueueTransition(std::unique_ptr<Layer> toLayer);

			static std::vector<std::unique_ptr<Transitions>> s_transitionQueue;
    };
}
