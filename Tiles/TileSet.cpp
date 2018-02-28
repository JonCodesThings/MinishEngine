#include "TileSet.h"

namespace minish
{
    void TileSet::addTile(Tile& tile)
    {
        for (auto& tile_ : m_tiles)
        {
            if (&tile_ == &tile)
            {
                return;
            }
        }
        m_tiles.push_back(tile);
        tile.m_tile_id = m_tile_count;
        m_tile_count++;
    }

    sf::Texture* const TileSet::getTexture()
    {
        return m_texture;
    }

    void TileSet::removeTile(unsigned int tile_id)
    {
        for (auto m_tiles_iter = m_tiles.begin(); m_tiles_iter != m_tiles.end(); m_tiles_iter++)
        {
            if ((*m_tiles_iter).m_tile_id == tile_id)
            {
                m_tiles.erase(m_tiles_iter);
                m_tile_count--;
               return;
            }
        }
    }

    void TileSet::setTexture(sf::Texture& texture)
    {
        m_texture = &texture;
    }
}