#ifndef MINISH_TEXTUREMANAGER_H
#define MINISH_TEXTUREMANAGER_H

#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>

namespace minish
{
    /*!
    * \brief Class for handling texture storage.
    * \author Jonathan Duncanson
    */
    class TextureManager
    {
        public:
            /*!
        	\brief Class method that gets a texture from storage by name.
        	*/
            sf::Texture& getTexture(const std::string& name);

            /*!
        	\brief Class method that loads and stores a texture by name.
        	*/
            bool loadTexture(const std::string& name, const std::string filepath);

            /*!
        	\brief Class method that removes a texture from memory.
        	*/
            void removeTexture(const std::string& name);
        private:
            /*!
        	\brief Map used to store textures.
        	*/
            std::unordered_map<std::string, sf::Texture> m_textures;
    };
}

#endif