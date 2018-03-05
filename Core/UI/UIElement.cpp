#include "UIElement.h"

#include <SFML/Graphics/RenderWindow.hpp>

namespace minish
{
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

    void UIElement::render(sf::RenderWindow* hwnd, sf::RenderStates states)
    {
        hwnd->draw(*this, states);

        for (auto& child_ : m_children)
        {
            child_->render(hwnd, states);
        }
    }

    void UIElement::setSize(sf::Vector2u& size)
    {
        m_size = size;
    }

    void UIElement::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(m_vertices, states);
    }
}