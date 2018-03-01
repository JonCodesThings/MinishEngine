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
        tile.m_tile_id = m_tiles.size();
        m_tiles.push_back(tile);
        
    }

    Tile* const TileSet::getTile(const unsigned int tile_id)
    {
        for (auto& tile_ : m_tiles)
        {
            if (tile_.m_tile_id == tile_id)
            {
                return &tile_;
            }
        }
        return nullptr;
    }

    unsigned int TileSet::getTileCount()
    {
        return m_tiles.size();
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
                return;
            }
        }
    }

    void TileSet::setTexture(sf::Texture& texture)
    {
        m_texture = &texture;
    }
}