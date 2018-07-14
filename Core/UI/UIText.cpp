#include "UIText.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>

namespace minish
{
    void UIText::setFont(const sf::Font& font)
    {
        m_font = font;
		m_text.setFont(m_font);
    }

	void UIText::render(minish::Frame& target, sf::RenderStates states)
	{
		target.blit(m_text, states);
		UIElement::render(target, states);
	}

	void UIText::setTextSize(unsigned int size)
	{
		m_text.setCharacterSize(size);
	}

    void UIText::setTextString(const std::string& text_string)
    {
        m_text.setString(text_string);
		m_text.setFillColor(sf::Color::Black);
    }

	void UIText::setPosition(const sf::Vector2f& position)
	{
		m_text.setPosition(position);
	}

	void UIText::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(m_text, states);
	}
}