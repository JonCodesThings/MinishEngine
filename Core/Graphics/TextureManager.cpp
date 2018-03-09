#include "TextureManager.h"

namespace minish
{
    const sf::Texture& TextureManager::getTexture(std::string& name)
    {
        std::unordered_map<std::string, sf::Texture>::iterator it = m_textures.find(name);

        if (it == m_textures.end())
        {
            return sf::Texture();
        }

        return m_textures[name];
    }

    bool TextureManager::loadTexture(std::string& name, std::string& filepath)
    {
        std::unordered_map<std::string, sf::Texture>::iterator it = m_textures.find(name);

        if (it == m_textures.end())
        {
            m_textures.insert((std::pair<std::string, sf::Texture>(name, sf::Texture())));
            if (m_textures[name].loadFromFile(filepath))
            {
                return true;
            }
            return false;
        }

        return false;
    }

    void TextureManager::removeTexture(std::string& name)
    {
        m_textures.erase(name);
    }
}