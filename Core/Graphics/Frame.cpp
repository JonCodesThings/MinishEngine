#include "Frame.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace minish
{
    Frame::Frame(sf::RenderTarget& target) : m_target(target)
    {
    }

    Frame::~Frame()
    {
    }

    void Frame::blit(const sf::Drawable& drawable, const sf::RenderStates states)
    {
		m_target.draw(drawable, states);
    }

    sf::RenderTarget& Frame::getRenderTarget()
    {
        return m_target;
    }

    const sf::View& Frame::getView() const
    {
        return m_target.getView();
    }

    void Frame::post_render()
    {
    }

    void Frame::pre_render()
    {
		m_target.clear(sf::Color::White);
    }

    void Frame::setView(const sf::View& view)
    {
		m_target.setView(view);
    }
}