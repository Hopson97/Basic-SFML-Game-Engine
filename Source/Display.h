#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <cstdint>
#include <SFML/Graphics.hpp>

namespace State
{
    class State_Base;
}

namespace Display
{
    void init   (const std::string& name = "Window");


    bool isOpen ();


    void update ();
    void clear  (const sf::Color& colour = {0, 0, 0});


    void draw(const sf::Drawable& drawable);


    void pollEvents(State::State_Base& gameState);

    constexpr uint16_t WIDTH  = 1280;
    constexpr uint16_t HEIGHT = 720;
}

#endif // DISPLAY_H_INCLUDED
