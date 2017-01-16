#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "State_Base.h"

namespace State
{
    class Playing : public State_Base
    {
        public:
            Playing (Application& application);

            void input  (const sf::Event& e);
            void input  ();
            void update (float dt);
            void draw   ();

        private:

    };
}

#endif // PLAYING_STATE_H_INCLUDED
