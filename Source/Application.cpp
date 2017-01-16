#include "Application.h"

#include "Display.h"
#include "Util/Random.h"

Application::Application()
{
    Display::init();
    Random::init();
}

void Application::runMainLoop()
{
    while (Display::isOpen())
    {
        auto event = Display::checkEvents();

        Display::clear();

        m_states.top()->input(event);

        Display::update();
    }
}


const Resource_Holder Application::getResources()
{
    return m_resourceHolder;
}

void Application::pushState(std::unique_ptr<State::State_Base> state)
{
    m_states.push(std::move(state));
}

void Application::popState()
{
    m_states.pop();
}
