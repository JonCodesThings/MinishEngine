#include "TileMap.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace minish
{
    const bool TileMap::generateTileMap()
    {
        if (m_generated)
        {
            return m_generated;
        }

        if (m_tilemap.size() < 1)
        {
            return m_generated;
        }

        if (m_map_size.x == 0 && m_map_size.y == 0)
        {
            return m_generated;
        }

        if (m_tile_size.x == 0.0f && m_tile_size.y == 0.0f)
        {
            return m_generated;
        }

        if (m_tileset.getTileCount() == 0 || m_tileset.getTexture() == nullptr)
        {
            return m_generated;
        }

        setPosition(0, 0);
        
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(m_tilemap.size() * 4);

        unsigned int AABB_count = 0;

        for (auto tile_ : m_tilemap)
        {
            if (m_tileset.getTile(tile_)->m_collidable)
            {
                AABB_count++;
            }
        }

        m_AABB.reserve(AABB_count);

        for (unsigned int height = 0; height < m_map_size.x; height++)
        {
            for (unsigned int width = 0; width < m_map_size.y; width++)
            {
                const Tile* tile_data = m_tileset.getTile(m_tilemap.at(width + height * m_map_size.x));

                sf::Vertex* current_tile = &m_vertices[(width + height * m_map_size.x) * 4];

                current_tile[0].position = sf::Vector2f(width * m_tile_size.x, height * m_tile_size.y);
                current_tile[1].position = sf::Vector2f((width + 1) * m_tile_size.x, height * m_tile_size.y);
                current_tile[2].position = sf::Vector2f((width + 1) * m_tile_size.x, (height + 1) * m_tile_size.y);
                current_tile[3].position = sf::Vector2f(width * m_tile_size.x, (height + 1) * m_tile_size.y);

                if (tile_data->m_collidable)
                {
                    m_AABB.push_back(sf::FloatRect(width * m_tile_size.x, height * m_tile_size.y, m_tile_size.x, m_tile_size.y));
                }

                current_tile[0].texCoords = sf::Vector2f(tile_data->m_texture_rect.left, tile_data->m_texture_rect.top);
                current_tile[1].texCoords = sf::Vector2f(tile_data->m_texture_rect.left + tile_data->m_texture_rect.width, tile_data->m_texture_rect.top);
                current_tile[2].texCoords = sf::Vector2f(tile_data->m_texture_rect.left + tile_data->m_texture_rect.width, tile_data->m_texture_rect.top + tile_data->m_texture_rect.height);
                current_tile[3].texCoords = sf::Vector2f(tile_data->m_texture_rect.left, tile_data->m_texture_rect.top + tile_data->m_texture_rect.height);
            }
        }

        m_generated = true;
        return m_generated;
    }

    const std::vector<sf::FloatRect>& TileMap::getAABBs() const
    {
        return m_AABB;
    }

    void TileMap::render(sf::RenderTarget& target)
    {
        target.draw(*this);
    }

    void TileMap::setMapSize(const unsigned int tilemap_width, const unsigned int tilemap_height)
    {
        m_map_size.x = tilemap_width;
        m_map_size.y = tilemap_height;
    }

    void TileMap::setMapSize(const sf::Vector2u& tilemap_size)
    {
        m_map_size = tilemap_size;
    }

    void TileMap::setTileSet(const TileSet& tileset)
    {
        m_tileset = tileset;
        m_texture = tileset.getTexture();
    }

    void TileMap::setTileSize(const float tile_width, const float tile_height)
    {
        m_tile_size.x = tile_width;
        m_tile_size.y = tile_height;
    }

    void TileMap::setTileSize(sf::Vector2f& tile_size)
    {
        m_tile_size = tile_size;
    }

    void TileMap::setTileMap(const std::vector<unsigned int>& tilemap)
    {
        m_tilemap = tilemap;
    }

    void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = m_texture;
        target.draw(m_vertices, states);
    }
}