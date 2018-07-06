#include "TextureManager.h"

namespace minish
{
    const sf::Texture& TextureManager::getTexture(const std::string& name) const
    {
        std::unordered_map<std::string, sf::Texture>::const_iterator it = m_textures.find(name);

        if (it == m_textures.end())
        {
            return m_textures.at("blank");
        }

        return m_textures.at(name);
    }

    bool TextureManager::loadTexture(const std::string& name, const std::string filepath)
    {
        std::unordered_map<std::string, sf::Texture>::iterator it = m_textures.find(name);

        if (it == m_textures.end())
        {
            it = m_textures.find("blank");
            if (it == m_textures.end())
            {
                 m_textures.insert((std::pair<std::string, sf::Texture>(name, sf::Texture())));
            }
            m_textures.insert((std::pair<std::string, sf::Texture>(name, sf::Texture())));
            if (m_textures[name].loadFromFile(filepath))
            {
                return true;
            }
            return false;
        }

        return false;
    }

    void TextureManager::removeTexture(const std::string& name)
    {
        m_textures.erase(name);
    }
}