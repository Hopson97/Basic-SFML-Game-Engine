#ifndef RESOURCE_HOLDER_H_INCLUDED
#define RESOURCE_HOLDER_H_INCLUDED

#include "Texture_Manager.h"
#include "Sound_Manager.h"
#include "Font_Manager.h"

struct Resource_Holder
{
    Texture_Manager textures;
    Font_Manager    fonts;
    Sound_Manager   sounds;
};

#endif // RESOURCE_HOLDER_H_INCLUDED
