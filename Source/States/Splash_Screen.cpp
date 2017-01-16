#include "Splash_Screen.h"

#include "../Display.h"
#include "../Application.h"
#include "Playing_State.h"

namespace State
{
    Splash_Screen::Splash::Splash(float time, const sf::Texture& splash)
    :   m_time (time)
    {
        m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        m_sprite.setTexture(&splash);
    }


    Splash_Screen::Splash::Splash(float time, const sf::Texture& splash, const sf::SoundBuffer& sound)
    :   m_time (time)
    {
        m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        m_sprite.setTexture(&splash);

        m_sound = std::make_unique<sf::Sound>(sound);
    }

    void Splash_Screen::Splash::start()
    {
        if (m_sound)
        {
            m_sound->play();
        }
        m_clock.restart();
    }

    void Splash_Screen::Splash::draw()
    {
        Display::draw(m_sprite);
    }


    bool Splash_Screen::Splash::isOver()
    {
        return (m_clock.getElapsedTime().asSeconds() >= m_time);
    }


    Splash_Screen::Splash_Screen(Application& application)
    :   State_Base (application)
    {
        m_fadeSprite.setFillColor({0, 0, 0,255});
        m_fadeSprite.setSize({Display::WIDTH, Display::HEIGHT});

        m_splashes.push({0.3, getTexture(Texture_ID::Splash_SFML)});
        m_splashes.push({1.4, getTexture(Texture_ID::Splash_MH), getSound(Sound_ID::Splash_Made_By)});
    }

    void Splash_Screen::input(const sf::Event& e)
    { }

    void Splash_Screen::input()
    { }

    void Splash_Screen::update(float dt)
    {

    }

    void Splash_Screen::draw()
    {
        if (!m_splashes.empty())
        {
            m_splashes.top().draw();

            switch (m_currSplashState)
            {
                case Splash_State::Enter:
                    if (m_currAlphaValue > 0)
                    {
                        m_fadeSprite.setFillColor({0, 0, 0, (sf::Uint8)m_currAlphaValue--});
                    }
                    else
                    {
                        m_currSplashState = Splash_State::Active;
                        m_splashes.top().start();
                    }
                    break;

                case Splash_State::Active:
                    if (m_splashes.top().isOver())
                        m_currSplashState = Splash_State::Exiting;
                    break;

                case Splash_State::Exiting:
                    if (m_currAlphaValue < 255)
                    {
                        m_fadeSprite.setFillColor({0, 0, 0, (sf::Uint8)m_currAlphaValue++});
                    }
                    else
                    {
                        m_currSplashState = Splash_State::Enter;
                        m_splashes.pop();
                    }
                    break;
            }
            Display::draw(m_fadeSprite);
        }
        else
        {
            m_p_application->pushState(std::make_unique<State::Playing>(*m_p_application));
        }
    }

}
