#include "GraphicsComponent.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "Core/Entity/Entity.h"

namespace minish
{
    GraphicsComponent::GraphicsComponent() : 
    m_transform_update_flag(true), m_vertex_update_flag(true), m_rotation(0.0f), m_position(0.0f, 0.0f), m_scale(1.0f, 1.0f), 
    m_texture(nullptr), m_texture_rect(), m_size(1, 1)
    {
        m_vertices.resize(4);
    }

    GraphicsComponent::GraphicsComponent(sf::Texture& texture, sf::IntRect& texture_rect, sf::Vector2u& size) :
    m_transform_update_flag(true), m_vertex_update_flag(true), m_rotation(0.0f), m_position(0.0f, 0.0f), m_scale(1.0f, 1.0f),
    m_texture(&texture), m_texture_rect(texture_rect),  m_size(size)
    {
        m_vertices.resize(4);
    }

    void GraphicsComponent::render(Frame& target)
    {
        target.blit(*this);
    }

    void GraphicsComponent::setColor(sf::Color& color)
    {
        m_color = color;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::setPosition(sf::Vector2f& position)
    {
        m_position = position;
        m_transform_update_flag = true;
    }

    void GraphicsComponent::setRotation(float rotation)
    {
        m_rotation = rotation;
        m_transform_update_flag = true;
    }

    void GraphicsComponent::setScale(sf::Vector2f& scale)
    {
        m_scale = scale;
        m_transform_update_flag = true;
    }

    void GraphicsComponent::setSize(sf::Vector2u& size)
    {
        m_size = size;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::setTexture(sf::Texture& texture)
    {
        m_texture = &texture;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::setTextureRect(sf::IntRect& texture_rect)
    {
        m_texture_rect = texture_rect;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::update(const float dt)
    {
        if (m_transform_update_flag)
        {
            m_transform = sf::Transform::Identity;
            m_transform.scale(m_scale);
            m_transform.rotate(m_rotation);
            m_transform.translate(m_position);

            getEntity()->getDataComponent().setData("graphics_scale", m_scale);
            getEntity()->getDataComponent().setData("graphics_rotation", m_rotation);
            getEntity()->getDataComponent().setData("graphics_position", m_position);

            m_transform_update_flag = false;
        }

        if (m_vertex_update_flag)
        {
            m_vertices[0].position = sf::Vector2f(0, 0);
            m_vertices[1].position = sf::Vector2f(m_size.x, 0);
            m_vertices[2].position = sf::Vector2f(m_size.x, m_size.y);
            m_vertices[3].position = sf::Vector2f(0, m_size.y);

            m_vertices[0].texCoords = sf::Vector2f(m_texture_rect.left, m_texture_rect.top);
            m_vertices[1].texCoords = sf::Vector2f(m_texture_rect.left + m_texture_rect.width, m_texture_rect.top);
            m_vertices[2].texCoords = sf::Vector2f(m_texture_rect.left + m_texture_rect.width, m_texture_rect.top + m_texture_rect.height);
            m_vertices[3].texCoords = sf::Vector2f(m_texture_rect.left, m_texture_rect.top + m_texture_rect.height);

            m_vertices[0].color = m_color;
            m_vertices[1].color = m_color;
            m_vertices[2].color = m_color;
            m_vertices[3].color = m_color;

            getEntity()->getDataComponent().setData("graphics_color", m_color);
            getEntity()->getDataComponent().setData("graphics_size", m_size);
            getEntity()->getDataComponent().setData("graphics_texture", m_texture);
            getEntity()->getDataComponent().setData("graphics_texture_rect", m_texture_rect);

            m_vertex_update_flag = false;
        };
    }

    void GraphicsComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= m_transform;
        states.texture = m_texture;
        target.draw(m_vertices, states);
    }
}