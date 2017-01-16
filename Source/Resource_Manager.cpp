#include "Resource_Manager.h"

Texture_Manager::Texture_Manager()
{
    std::string path ("Res/Textures/");

    registerResource(Texture_ID::Splash_SFML, path + "Splash/SFML.png");
    registerResource(Texture_ID::Splash_MH,   path + "Splash/MatthewHopson.png");
    registerResource(Texture_ID::Arrow_Test,   path + "Arrows.png");
}

Font_Manager::Font_Manager()
{
    std::string path ("Res/Fonts/");

    registerResource(Font_ID::RS, path + "rs.ttf");
}

Sound_Manager::Sound_Manager()
{
    std::string path ("Res/Sounds/");

    registerResource(Sound_ID::Splash_Made_By, path + "MadeBy.ogg");
}
