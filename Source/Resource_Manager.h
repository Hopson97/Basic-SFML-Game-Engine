#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED

#include <map>
#include <SFML/Graphics.hpp>

enum class Texture_ID
{

};

enum class Font_ID
{

};


template<typename Resource, typename Enum>
class Resource_Manager
{
    public:
        const Resource& get(Enum e) const
        {
            return m_resources[e];
        }

    protected:
        void registerResource(Enum key, const Resource& resource)
        {
            m_resources.insert(std::make_pair(key, resource));
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

struct Resource_Holder
{
    Texture_Manager textureManager;
    Font_Manager    fontManager;
};

#endif // RESOURCEMANAGER_H_INCLUDED
