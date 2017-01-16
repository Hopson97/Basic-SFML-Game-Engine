#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED

#include <map>
#include <stdexcept>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum class Texture_ID
{
    Splash_SFML,
    Splash_MH
};

enum class Font_ID
{

};

enum class Sound_ID
{
    Splash_Made_By
};


template<typename Resource, typename Enum>
class Resource_Manager
{
    public:
        const Resource& get(Enum e) const
        {
            return m_resources.at(e);
        }

    protected:
        void registerResource(Enum key, const std::string& filename)
        {
            Resource res;
            if (!res.loadFromFile(filename))
            {
                throw std::runtime_error ("Could load resource: " + filename + "!");
            }
            m_resources.insert(std::make_pair(key, res));
        }

    private:
        std::map<Enum, Resource> m_resources;
};

class Texture_Manager : public Resource_Manager<sf::Texture, Texture_ID>
{
    public:
        Texture_Manager();
};

class Font_Manager : public Resource_Manager<sf::Font, Font_ID>
{
    public:
        Font_Manager();
};

class Sound_Manager : public Resource_Manager<sf::SoundBuffer, Sound_ID>
{
    public:
        Sound_Manager();
};

struct Resource_Holder
{
    Texture_Manager textures;
    Font_Manager    fonts;
    Sound_Manager   sounds;
};



#endif // RESOURCEMANAGER_H_INCLUDED
