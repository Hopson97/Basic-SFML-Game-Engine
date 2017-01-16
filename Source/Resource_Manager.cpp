#include "Resource_Manager.h"

Texture_Manager::Texture_Manager()
{
    std::string texturePath ("Res/Textures/");

    registerResource(Texture_ID::Splash_SFML, texturePath + "Splash/SFML.png");
}

Font_Manager::Font_Manager()
{
    std::string texturePath ("Res/Fonts/");
}
