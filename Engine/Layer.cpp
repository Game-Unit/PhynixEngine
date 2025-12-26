#include "Layer.h"

#include "Application.h"
#include <memory>

std::vector<std::unique_ptr<Engine_Core::Layer::Transitions>> Engine_Core::Layer::s_transitionQueue;

void Engine_Core::Layer::QueueTransition(std::unique_ptr<Layer> toLayer)
{
    auto& layerStack = Application::Get().m_LayerStack;
    for (auto& layer : layerStack)
    {
       	if (layer.get() == this)
       	{
            auto transition = std::make_unique<Transitions>(*layer, *toLayer);
            s_transitionQueue.push_back(std::move(transition));
            return;
       	}
    }
}

void Engine_Core::Layer::Transition()
{
    for (auto& transition : s_transitionQueue)
    {
        transition->originalLayer = std::move(transition->transitionLayer);
    }

    s_transitionQueue.clear();
}
