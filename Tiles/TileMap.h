#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "TileSet.h"

namespace sf
{
    class RenderWindow;
}

namespace minish
{
    /*!
    * \brief TileMap class to store an entire tilemap.
    * \author Jonathan Duncanson
    */
    class TileMap : public sf::Drawable, public sf::Transformable
    {
        public:
            /*!
            \brief Generates the tilemap. Returns true if successful. Returns false if a required component is not set.
            */
            bool generateTileMap();

            /*!
            \brief Renders the tilemap.
            */
            void render(sf::RenderWindow* hwnd);

            /*!
            \brief Sets the size of the tilemap.
            */
            void setMapSize(const unsigned int tilemap_width, const unsigned int tilemap_height);

            /*!
            \brief Sets the size of the tilemap.
            */
            void setMapSize(sf::Vector2u& tilemap_size);

            /*!
            \brief Sets the tileset of the tilemap.
            */
            void setTileSet(TileSet& tileset);

            /*!
            \brief Sets the size of one tile.
            */
            void setTileSize(const float tile_width, const float tile_height);

            /*!
            \brief Sets the size of one tile.
            */
            void setTileSize(sf::Vector2f& tile_size);

            //void setTileMap(std::string& filepath);

            /*!
            \brief Sets the actual tilemap data.
            */
            void setTileMap(std::vector<unsigned int>& tilemap);
        private:
            /*!
            \brief Required SFML rendering function.
            */
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            /*!
            \brief Stores whether or not the tilemap has been fully generated.
            */
            bool m_generated = false;

            /*!
            \brief Stores a copy of the tileset.
            */
            TileSet m_tileset;

            /*!
            \brief Stores the raw tilemap data.
            */
            std::vector<unsigned int> m_tilemap;

            /*!
            \brief Stores all collidable tiles' AABB.
            */
            std::vector<sf::FloatRect> m_AABB;

            /*!
            \brief Stores a pointer to the tilemap texture.
            */
            sf::Texture* m_texture = nullptr;

            /*!
            \brief Stores the size of the tilemap.
            */
            sf::Vector2u m_map_size;

            /*!
            \brief Stores the size of a tile.
            */
            sf::Vector2f m_tile_size;

            /*!
            \brief Stores the tilemap's vertex array.
            */
            sf::VertexArray m_vertices;
    };
}