#ifndef MINISH_TEXTUREMANAGER_H
#define MINISH_TEXTUREMANAGER_H

#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>

namespace minish
{
    class TextureManager
    {
        public:
            const sf::Texture& getTexture(std::string& name);
            bool loadTexture(std::string& name, std::string& filepath);
            void removeTexture(std::string& name);
        private:
            std::unordered_map<std::string, sf::Texture> m_textures;
    };
}

#endif