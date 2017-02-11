#include "Texture_Manager.h"

Texture_Manager::Texture_Manager()
{
    std::string path ("Res/Textures/");

    registerResource(Texture_ID::Splash_SFML,   path + "Splash/SFML.png");
    registerResource(Texture_ID::Splash_MH,     path + "Splash/MatthewHopson.png");
    registerResource(Texture_ID::Arrow_Test,    path + "Arrows.png");
}
