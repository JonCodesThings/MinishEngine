#ifndef MINISH_GRAPHICSCOMPONENT_H
#define MINISH_GRAPHICSCOMPONENT_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

#include "Core/Entity/Component.h"
#include "Core/Physics/AABB.h"

namespace minish
{
    class GraphicsComponent : public Component, public sf::Drawable, public sf::Transformable
    {
        public:
            GraphicsComponent();
            GraphicsComponent(sf::Texture& texture, sf::IntRect& texture_rect, sf::Vector2u& size);
            virtual void render(sf::RenderWindow* hwnd);
            void setSize(sf::Vector2u& size);
            void setTexture(sf::Texture& texture);
            void setTextureRect(sf::IntRect& texture_rect);
            virtual void update(const float dt);
        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            bool m_update_flag;
            sf::Texture* m_texture;
            sf::IntRect m_texture_rect;
            sf::Vector2u m_size;
            sf::VertexArray m_vertices;
    };
}

#endif