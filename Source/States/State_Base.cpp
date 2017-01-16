#include "State_Base.h"

#include "../Application.h"

namespace State
{
    State_Base::State_Base(Application& app)
    :   m_p_application (&app)
    {

    }

    const sf::Texture& State_Base::getTexture(Texture_ID id) const
    {
        return m_p_application->getResources().textures.get(id);
    }

    const sf::Font& State_Base::getFont(Font_ID id) const
    {
        return m_p_application->getResources().fonts.get(id);
    }

    const sf::SoundBuffer& State_Base::getSound(Sound_ID id) const
    {
        return m_p_application->getResources().sounds.get(id);
    }

}
