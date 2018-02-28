#include "TileMap.h"

namespace minish
{
    bool TileMap::generateTileMap()
    {
        if (m_tilemap.size() < 1)
        {
            return m_generated;
        }

        if (m_size.x == 0 && m_size.y == 0)
        {
            return m_generated;
        }

        if (m_tile_size.x == 0.0f && m_tile_size.y == 0.0f)
        {
            return m_generated;
        }

        if (m_tileset.getTileCount() == 0 || m_tileset.getTexture == nullptr)
        {
            return m_generated;
        }
    }
}