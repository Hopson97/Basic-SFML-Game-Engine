#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <memory>
#include <stack>

#include "Resource_Manager.h"
#include "States/State_Base.h"

//Cheeky defines to avoid longlineitus
#define GET_RES m_p_application->getResources()

#define GET_APP_TEXTURE(id) GET_RES.textures.   get(id)
#define GET_APP_FONT(id)    GET_RES.fonts.      get(id)
#define GET_APP_SOUND(id)   GET_RES.sounds.     get(id)

class Application
{
    public:
        Application();

        void runMainLoop();

        const Resource_Holder& getResources() const;

        void pushState(std::unique_ptr<State::State_Base> state);
        void popState ();

    private:
        Resource_Holder m_resourceHolder;

        std::stack<std::unique_ptr<State::State_Base>> m_states;
};

#endif // APPLICATION_H_INCLUDED
