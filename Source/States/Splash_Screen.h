#ifndef SPLASH_SCREEN_H_INCLUDED
#define SPLASH_SCREEN_H_INCLUDED

#include <stack>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "State_Base.h"


namespace State
{
    class Splash_Screen : public State_Base
    {
        class Splash
        {
            public:
                Splash(float time, const sf::Texture& splash);
                Splash(float time, const sf::Texture& splash, const sf::SoundBuffer& sound);

                void start();
                void draw();
                bool isOver();

            private:
                float               m_time;
                sf::RectangleShape  m_sprite;
                sf::Clock           m_clock;
                std::unique_ptr<sf::Sound> m_sound;
        };

        enum class Splash_State
        {
            Enter,
            Active,
            Exiting
        };

        public:
            Splash_Screen (Application& application);

            void input  (const sf::Event& e);
            void input  ();
            void update (float dt);
            void draw   ();

        private:
            std::stack<Splash>  m_splashes;
            sf::RectangleShape  m_fadeSprite;
            Splash_State        m_currSplashState   = Splash_State::Enter;
            int                 m_currAlphaValue    = 255;
    };
}

#endif // SPLASH_SCREEN_H_INCLUDED
