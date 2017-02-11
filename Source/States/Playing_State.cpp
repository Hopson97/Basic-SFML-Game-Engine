#include "Playing_State.h"

#include "../Resource_Managers/Resource_Manager.h"
#include "../Application.h"
#include "../Display.h"

namespace State
{
    Playing::Playing(Application& application)
    :   State_Base (application)
    {
        m_animSprite.setTexture(&getTexture(Texture_ID::Arrow_Test));
        m_animSprite.setSize({500, 500});

        for (int i = 0; i < 4 ; i++)
        {
            m_anim.addFrame({i * 16, 0, 16, 16}, 0.1);
        }

        m_text.setFont(getFont(Font_ID::RS));
        m_text.setString("Test.");
    }

    void Playing::input(const sf::Event& e)
    {

    }

    void Playing::input()
    {

    }

    void Playing::update(float dt)
    {
        m_animSprite.setTextureRect(m_anim.getFrame());
    }

    void Playing::draw()
    {
        Display::draw(m_animSprite);
        Display::draw(m_text);
    }

}
