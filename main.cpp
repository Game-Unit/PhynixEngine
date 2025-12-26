#include "Engine/Application.h"

int main()
{
    Engine_Core::ApplicationSettings settings;
    settings.applicationName = "Survial Game";
    settings.width = 1920;
    settings.hight = 1080;

    Engine_Core::Application app(settings);
}
