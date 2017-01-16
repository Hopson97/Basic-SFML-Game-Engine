#include "Application.h"

#include "Display.h"
#include "Util/Random.h"

#include "States/Splash_Screen.h"

Application::Application()
{
    Display::init();
    Random::init();

    pushState(std::make_unique<State::Splash_Screen>(*this));
}

void Application::runMainLoop()
{
    sf::Clock c;
    while (Display::isOpen())
    {
        auto dt = c.restart().asSeconds();
        auto event = Display::checkEvents();

        Display::clear();

        m_states.top()->input   (event);
        m_states.top()->input   ();
        m_states.top()->update  (dt);
        m_states.top()->draw    ();

        Display::update         ();
    }
}


const Resource_Holder& Application::getResources() const
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
