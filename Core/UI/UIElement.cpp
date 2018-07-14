#include "UIElement.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>

namespace minish
{
	UIElement::~UIElement()
	{

	}

    void UIElement::addChild(UIElement& element)
    {
        element.addParent(*this);
        m_children.push_front(&element);
    }

    void UIElement::addParent(UIElement& element)
    {
        if (m_parent)
        {
            m_parent->removeChild(*this);
            removeParent();
        }
        m_parent = &element;
    }

	const sf::Vector2u& UIElement::getSize() const
	{
		return m_size;
	}

    void UIElement::removeChild(UIElement& element)
    {
        for (auto& child_ : m_children)
        {
            if (child_ == &element)
            {
                m_children.remove(&element);
                return;
            }
        }
    }

    void UIElement::removeParent()
    {
        m_parent = nullptr;
    }


    void UIElement::render(minish::Frame& target, sf::RenderStates states)
    {
        target.blit(*this, states);
		states.transform *= getTransform();
        for (auto& child_ : m_children)
        {
            child_->render(target, states);
        }
    }

    void UIElement::setSize(const sf::Vector2u& size)
    {
        m_size = size;
    }

    void UIElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(m_vertices, states);
    }
}