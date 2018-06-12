#include "PhysicsComponent.h"

#include "Core/Entity/Entity.h"

namespace minish
{
    const AABB& PhysicsComponent::getAABB()
    {
        return m_AABB;
    }

    const sf::Vector2f& PhysicsComponent::getPosition()
    {
        return m_position;
    }

    const sf::Vector2u& PhysicsComponent::getSize()
    {
        return m_size;
    }

    void PhysicsComponent::setAABB(AABB& aabb)
    {
        m_AABB = aabb;
        if (getEntity() != nullptr)
        {
            minish::Data data;
            data.custom_data = (void*)&m_AABB;
            getEntity()->getDataComponent().setData("AABB", data);
        }
    }

    void PhysicsComponent::setPosition(sf::Vector2f& position)
    {
        m_position = position;
        m_AABB.left = m_position.x;
        m_AABB.top = m_position.y;
        if (getEntity() != nullptr)
        {
            minish::Data data;
            data.custom_data = (void*)&m_position;
            getEntity()->getDataComponent().setData("AABB_position", data);
        }
    }

    void PhysicsComponent::setSize(sf::Vector2u& size)
    {
        m_size = size;
        m_AABB.width = m_size.x;
        m_AABB.height = m_size.y;
        if (getEntity() != nullptr)
        {
            minish::Data data;
            data.custom_data = (void*)&m_size;
            getEntity()->getDataComponent().setData("AABB_size", data);
        }
    }
}