#include "UIButton.h"

#include "Core/System/Action.h"

namespace minish
{
	UIButton::UIButton()
	{
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(4);
	}

    AABB& UIButton::getAABB()
    {
		if (m_AABB.left != getPosition().x || m_AABB.top != getPosition().y)
		{
			m_AABB.left = getPosition().x;
			m_AABB.top = getPosition().y;
			m_AABB.width = getSize().x;
			m_AABB.height = getSize().y;
		}
        return m_AABB;
    }

    void UIButton::bindAction(Action& action)
    {
        if (m_action)
            unbindAction();

        m_action = &action;
    }

    void UIButton::onAction()
    {
        if (m_action)
            m_action->onAction();
    }

	void UIButton::setSize(const sf::Vector2u& size)
	{
		UIElement::setSize(size);
		m_vertices[0].position = sf::Vector2f(0, 0);
		m_vertices[1].position = sf::Vector2f(0 + size.x, 0);
		m_vertices[2].position = sf::Vector2f(0 + size.x, 0 + size.y);
		m_vertices[3].position = sf::Vector2f(0, 0 + size.y);

		m_vertices[0].color = sf::Color(255, 0, 0);
		m_vertices[1].color = sf::Color(255, 0, 0);
		m_vertices[2].color = sf::Color(255, 0, 0);
		m_vertices[3].color = sf::Color(255, 0, 0);
	}

    void UIButton::unbindAction()
    {
        m_action = nullptr;
    }
}