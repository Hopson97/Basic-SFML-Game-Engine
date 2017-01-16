#include "Display.h"

#include <memory>

namespace Display
{
    std::unique_ptr<sf::RenderWindow> d_window;

    void init(const std::string& name)
    {
        d_window = std::make_unique<sf::RenderWindow>(sf::VideoMode{WIDTH, HEIGHT},
                                                      name,
                                                      sf::Style::Close);
    }

    bool isOpen()
    {
        return d_window->isOpen();
    }

    sf::Event checkEvents()
    {
        sf::Event e;
        while (d_window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                d_window->close();
            }
        }
        return e;
    }

    void update()
    {
        d_window->display();
    }

    void clear (const sf::Color& colour)
    {
        d_window->clear(colour);
    }

    void draw(const sf::Drawable& drawable)
    {
        d_window->draw(drawable);
    }
}
