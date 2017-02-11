#include "Application.h"

#include <iostream>

#include "Display.h"
#include "Util/Random.h"

#include "States/Splash_Screen.h"

namespace
{
    void calculateFPS()
    {
        static sf::Clock timer;
        static sf::Clock printTimer;
        static auto numFrames = 0;

        numFrames++;

        if (printTimer.getElapsedTime().asSeconds() >= 1.0f)
        {
            auto fps = (float)numFrames / timer.getElapsedTime().asSeconds();
            printTimer.restart();
            std::cout << fps << std::endl;

            numFrames = 0;
            timer.restart();
}
    }
}

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

        Display::clear();

        m_states.top()->input   ();
        m_states.top()->update  (dt);
        m_states.top()->draw    ();

        Display::update         ();
        calculateFPS            ();

        Display::pollEvents(*m_states.top());
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
