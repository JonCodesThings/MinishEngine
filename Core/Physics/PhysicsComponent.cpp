#include "PhysicsComponent.h"

namespace minish
{
    const AABB& PhysicsComponent::getAABB()
    {
        return m_AABB;
    }

    sf::Vector2f PhysicsComponent::getPosition()
    {
        return sf::Vector2f(m_AABB.left, m_AABB.top);
    }

    sf::Vector2u PhysicsComponent::getSize()
    {
        return sf::Vector2u(m_AABB.width, m_AABB.height);
    }

    void PhysicsComponent::setAABB(AABB& aabb)
    {
        m_AABB = aabb;
    }

    void PhysicsComponent::setPosition(sf::Vector2f& position)
    {
        m_AABB.left = position.x;
        m_AABB.top = position.y;
    }

    void PhysicsComponent::setSize(sf::Vector2u& size)
    {
        m_AABB.width = size.x;
        m_AABB.height = size.y;
    }
}