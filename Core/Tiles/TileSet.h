#ifndef MINISH_TILESET_H
#define MINISH_TILESET_H

#include <vector>
#include <SFML/Graphics/Rect.hpp>

namespace sf
{
    class Texture;
}

namespace minish
{
    /*!
    * \brief Struct to store tile data.
    * \author Jonathan Duncanson
    */
    struct Tile
    {
        Tile(bool collidable, sf::IntRect texture_rect) : 
            m_collidable(collidable), m_texture_rect(texture_rect) {};
        unsigned int m_tile_id;
        bool m_collidable;
        sf::FloatRect m_texture_rect;
    };

    /*!
    * \brief Class to store a tileset.
    * \author Jonathan Duncanson
    */
    class TileSet
    {
        public:
            /*!
            \brief Class method to add a tile to the tileset.
            */
            void addTile(Tile& tile);

            /*!
            \brief Returns a pointer to the tile with the given id. Returns nullptr if it can't find it.
            */
            const Tile* getTile(const unsigned int tile_id) const;

            /*!
            \brief Returns the number of tiles in the tileset.
            */
            const unsigned int getTileCount() const;

            /*!
            \brief Returns a const pointer to the texture used by the tileset. Will return nullptr if one hasn't been set yet.
            */
            sf::Texture* const getTexture() const;

            /*!
            \brief Class method to remove a tile from the tileset.
            */
            void removeTile(const unsigned int tile_id);

            /*!
            \brief Sets the texture for the tileset.
            */
            void setTexture(sf::Texture& texture);
        private:
            /*!
            \brief Vector to store all tiles in the tileset.
            */
            std::vector<Tile> m_tiles;

            /*!
            \brief Pointer to the tileset's texture.
            */
            sf::Texture* m_texture = nullptr;
    };
}

#endif