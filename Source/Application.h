#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <memory>
#include <stack>

#include "Resource_Managers/Resource_Holder.h"
#include "States/State_Base.h"

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
