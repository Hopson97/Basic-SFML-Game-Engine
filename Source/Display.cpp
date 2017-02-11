#include "Display.h"

#include "States/State_Base.h"

namespace Display
{
    namespace
    {
        sf::RenderWindow window;

        void checkForClose(const sf::Event& e)
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    void init(const std::string& name)
    {
        window.create({WIDTH, HEIGHT},
                       name,
                       sf::Style::Close);
    }

    bool isOpen()
    {
        return window.isOpen();
    }

    void update()
    {
        window.display();
    }

    void clear (const sf::Color& colour)
    {
        window.clear(colour);
    }

    void draw(const sf::Drawable& drawable)
    {
        window.draw(drawable);
    }

    void pollEvents(State::State_Base& gameState)
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            gameState.input(e);
            checkForClose(e);
        }
    }

}
