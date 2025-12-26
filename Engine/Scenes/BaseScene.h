#include <iostream>

#include "../Scene.h"

class BaseScene : public Engine_Core::Scene
{
    void Start() override
    {
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "YOU ARE USING THE BASE SCENE!" << std::endl;
        std::cout << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
    }

    void Update() override {}
    void RenderUI() override {}
};
