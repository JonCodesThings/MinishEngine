#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "TileSet.h"

namespace sf
{
    class RenderWindow;
}

namespace minish
{
    class TileMap : public sf::Drawable
    {
        public:
            bool generateTileMap();
            void render(sf::RenderWindow* hwnd);
            void setSize(const unsigned int tilemap_width, const unsigned int tilemap_height);
            void setSize(sf::Vector2u& tilemap_size);
            void setTileSet(TileSet& tileset);
            void SetTileSize(const float tile_width, const float tile_height);
            void SetTileSize(sf::Vector2f& tile_size);
            void setTileMap(std::string& filepath);
            void setTileMap(std::vector<unsigned int>& tilemap);
        private:
            bool m_generated = false;
            TileSet m_tileset;
            std::vector<unsigned int> m_tilemap;
            sf::Vector2u m_size;
            sf::Vector2f m_tile_size;
            sf::VertexArray m_vertices;
    };
}