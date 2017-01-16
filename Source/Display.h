#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <cstdint>
#include <SFML/Graphics.hpp>

namespace Display
{
    void init               (const std::string& name = "Window");
    bool isOpen             ();
    sf::Event checkEvents   ();

    void update();
    void clear (const sf::Color& colour = {0, 0, 0});

    void draw(const sf::Drawable& drawable);

    constexpr uint16_t WIDTH  = 1280;
    constexpr uint16_t HEIGHT = 720;
}

#endif // DISPLAY_H_INCLUDED
