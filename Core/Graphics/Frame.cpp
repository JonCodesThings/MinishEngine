#include "Frame.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

namespace minish
{
    Frame::Frame() : m_hwnd(nullptr)
    {
    }

    Frame::~Frame()
    {
    }

    void Frame::blit(const sf::Drawable& drawable, const sf::RenderStates states)
    {
        m_frame.draw(drawable);
    }

    void Frame::deinit()
    {}

    sf::RenderTarget& Frame::getRenderTarget()
    {
        return m_frame;
    }

    bool Frame::init(const sf::Vector2u& size, sf::RenderWindow& hwnd)
    {
        m_vertices.setPrimitiveType(sf::PrimitiveType::Quads);
        m_vertices.resize(4);
        m_hwnd = &hwnd;
        if(!m_frame.create(size.x, size.y))
        {
            return false;
        }

        m_vertices[0].position = sf::Vector2f(0, 0);
        m_vertices[1].position = sf::Vector2f(m_frame.getSize().x, 0);
        m_vertices[2].position = sf::Vector2f(m_frame.getSize().x, m_frame.getSize().y);
        m_vertices[3].position = sf::Vector2f(0, m_frame.getSize().y);

        m_vertices[0].texCoords = sf::Vector2f(0, 0);
        m_vertices[1].texCoords = sf::Vector2f(m_frame.getSize().x, 0);
        m_vertices[2].texCoords = sf::Vector2f(m_frame.getSize().x, m_frame.getSize().y);
        m_vertices[3].texCoords = sf::Vector2f(0, m_frame.getSize().y);
        return true;
    }

    void Frame::post_render()
    {
        m_frame.display();
    }

    void Frame::pre_render()
    {
        m_frame.clear(sf::Color::White);
    }

    void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        states.texture = &m_frame.getTexture();

        target.draw(m_vertices, states);
    }
}