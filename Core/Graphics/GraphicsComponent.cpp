#include "GraphicsComponent.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include "Core/Entity/Entity.h"

#include <iostream>

namespace minish
{
    GraphicsComponent::GraphicsComponent() : 
    m_texture(nullptr), m_color(0, 0, 0), m_texture_rect(), m_size(1, 1)
    {
        m_vertices.resize(4);
        m_vertices.setPrimitiveType(sf::Quads);
    }

    GraphicsComponent::GraphicsComponent(sf::Texture& texture, sf::IntRect& texture_rect, sf::Vector2u& size) :
    m_texture(&texture), m_texture_rect(texture_rect),  m_size(size)
    {
        m_vertices.resize(4);
        m_vertices.setPrimitiveType(sf::Quads);
    }

    const sf::Color& GraphicsComponent::getColor() const
    {
        return m_color;
    }

    const sf::Vector2u& GraphicsComponent::getSize() const
    {
        return m_size;
    }

    const sf::Texture* GraphicsComponent::getTexture() const
    {
        return m_texture;
    }

    const sf::IntRect& GraphicsComponent::getTextureRect() const
    {
        return m_texture_rect;
    }

    void GraphicsComponent::render(sf::RenderTarget& target, sf::RenderStates states)
    {
		if (m_vertex_update_flag)
		{
			m_vertices[0].position = sf::Vector2f(-((float)m_size.x / 2.0f), -((float)m_size.y / 2.0f));
			m_vertices[1].position = sf::Vector2f(((float)m_size.x / 2.0f), -((float)m_size.y / 2.0f));
			m_vertices[2].position = sf::Vector2f(((float)m_size.x / 2.0f), ((float)m_size.y / 2.0f));
			m_vertices[3].position = sf::Vector2f(-((float)m_size.x / 2.0f), ((float)m_size.y / 2.0f));

			m_vertices[0].texCoords = sf::Vector2f(m_texture_rect.left, m_texture_rect.top);
			m_vertices[1].texCoords = sf::Vector2f(m_texture_rect.left + m_texture_rect.width, m_texture_rect.top);
			m_vertices[2].texCoords = sf::Vector2f(m_texture_rect.left + m_texture_rect.width, m_texture_rect.top + m_texture_rect.height);
			m_vertices[3].texCoords = sf::Vector2f(m_texture_rect.left, m_texture_rect.top + m_texture_rect.height);

			m_vertices[0].color = m_color;
			m_vertices[1].color = m_color;
			m_vertices[2].color = m_color;
			m_vertices[3].color = m_color;

#ifdef MINISH_EXPERIMENTAL
			if (getEntity() != nullptr)
			{
				getEntity()->getDataComponent().setData("graphics_color", m_color);
				getEntity()->getDataComponent().setData("graphics_size", m_size);
				getEntity()->getDataComponent().setData("graphics_texture", m_texture);
				getEntity()->getDataComponent().setData("graphics_texture_rect", m_texture_rect);
			}
#endif
			m_vertex_update_flag = false;
		}

        target.draw(*this, getEntity()->getTransform());
    }

    void GraphicsComponent::setColor(const sf::Color& color)
    {
        m_color = color;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::setSize(const sf::Vector2u& size)
    {
        m_size = size;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::setTexture(const sf::Texture& texture)
    {
        m_texture = &texture;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::setTextureRect(const sf::IntRect& texture_rect)
    {
        m_texture_rect = texture_rect;
        m_vertex_update_flag = true;
    }

    void GraphicsComponent::setEntity(Entity& entity)
    {
        Component::setEntity(entity);
#ifdef MINISH_EXPERIMENTAL
        getEntity()->getDataComponent().registerData("graphics_scale", m_scale);
        getEntity()->getDataComponent().registerData("graphics_rotation", m_rotation);
        getEntity()->getDataComponent().registerData("graphics_position", m_position);
        getEntity()->getDataComponent().registerData("graphics_color", m_color);
        getEntity()->getDataComponent().registerData("graphics_size", m_size);
        getEntity()->getDataComponent().registerData("graphics_texture", m_texture);
        getEntity()->getDataComponent().registerData("graphics_texture_rect", m_texture_rect);
#endif
    }

    void GraphicsComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        //states.transform *= ;
        states.texture = m_texture;
        target.draw(m_vertices, states);
    }
}