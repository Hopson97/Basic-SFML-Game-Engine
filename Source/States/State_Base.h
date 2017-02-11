#ifndef STATE_BASE_H_INCLUDED
#define STATE_BASE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Resource_Managers/Resource_Holder.h"

class Application;

namespace State
{
    class State_Base
    {
        public:
            State_Base(Application& app);
            virtual ~State_Base() {}

            virtual void input  (const sf::Event& e)    = 0;
            virtual void input  ()                      = 0;
            virtual void update (float dt)              = 0;
            virtual void draw   ()                      = 0;

        protected:
            const sf::Texture&      getTexture (Texture_ID id) const;
            const sf::Font&         getFont    (Font_ID    id) const;
            const sf::SoundBuffer&  getSound   (Sound_ID   id) const;

        protected:
            Application* m_p_application;

    };
}

#endif // STATE_BASE_H_INCLUDED
