#include "GraphicsComponent.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace minish
{
    GraphicsComponent::GraphicsComponent() : m_update_flag(true), m_texture(nullptr), m_texture_rect(), m_size(1, 1)
    {
        m_vertices.resize(4);
    }

    GraphicsComponent::GraphicsComponent(sf::Texture& texture, sf::IntRect& texture_rect, sf::Vector2u& size) :
    m_update_flag(true), m_texture(&texture), m_texture_rect(texture_rect), m_size(size)
    {
        m_vertices.resize(4);
    }

    void GraphicsComponent::render(sf::RenderTarget& target)
    {
        target.draw(*this);
    }

    void GraphicsComponent::setSize(sf::Vector2u& size)
    {
        m_size = size;
    }

    void GraphicsComponent::setTexture(sf::Texture& texture)
    {
        m_texture = &texture;
        m_update_flag = true;
    }

    void GraphicsComponent::setTextureRect(sf::IntRect& texture_rect)
    {
        m_texture_rect = texture_rect;
        m_update_flag = true;
    }

    void GraphicsComponent::update(const float dt)
    {
        if (m_update_flag)
        {
            m_vertices[0].position = sf::Vector2f(0, 0);
            m_vertices[1].position = sf::Vector2f(m_size.x, 0);
            m_vertices[2].position = sf::Vector2f(m_size.x, m_size.y);
            m_vertices[3].position = sf::Vector2f(0, m_size.y);

            m_vertices[0].texCoords = sf::Vector2f(m_texture_rect.left, m_texture_rect.top);
            m_vertices[1].texCoords = sf::Vector2f(m_texture_rect.left + m_texture_rect.width, m_texture_rect.top);
            m_vertices[2].texCoords = sf::Vector2f(m_texture_rect.left + m_texture_rect.width, m_texture_rect.top + m_texture_rect.height);
            m_vertices[3].texCoords = sf::Vector2f(m_texture_rect.left, m_texture_rect.top + m_texture_rect.height);
        };
    }

    void GraphicsComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = m_texture;
        target.draw(m_vertices, states);
    }
}