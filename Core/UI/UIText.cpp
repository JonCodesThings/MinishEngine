#include "UIText.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace minish
{
    void UIText::setFont(sf::Font& font)
    {
        m_font = font;
		m_text.setFont(m_font);
    }

	void UIText::render(sf::RenderWindow* hwnd, sf::RenderStates states)
	{
		hwnd->draw(m_text, states);
		UIElement::render(hwnd, states);
	}

	void UIText::setTextSize(unsigned int size)
	{
		m_text.setCharacterSize(size);
	}

    void UIText::setTextString(std::string& text_string)
    {
        m_text.setString(text_string);
		m_text.setFillColor(sf::Color::Red);
    }

	void UIText::setPosition(sf::Vector2f position)
	{
		m_text.setPosition(position);
	}

	void UIText::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(m_text, states);
	}
}