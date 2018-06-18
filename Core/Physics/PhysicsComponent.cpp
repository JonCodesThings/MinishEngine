#include "PhysicsComponent.h"

#include "Core/Entity/Entity.h"

namespace minish
{
    const AABB& PhysicsComponent::getAABB()
    {
        return m_AABB;
    }

    const sf::Vector2f& PhysicsComponent::getAcceleration()
    {
        return m_acceleration;
    }

    const sf::Vector2f& PhysicsComponent::getPosition()
    {
        return m_position;
    }

    const sf::Vector2u& PhysicsComponent::getSize()
    {
        return m_size;
    }

    const sf::Vector2f& PhysicsComponent::getVelocity()
    {
        return m_velocity;
    }

    void PhysicsComponent::setAABB(AABB& aabb)
    {
        m_AABB = aabb;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("AABB", m_AABB);
        }
    }

    void PhysicsComponent::setAcceleration(sf::Vector2f& acceleration)
    {
        m_acceleration = acceleration;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("physics_acceleration", m_acceleration);
        }
    }

    void PhysicsComponent::setPosition(sf::Vector2f& position)
    {
        m_position = position;
        m_AABB.left = m_position.x;
        m_AABB.top = m_position.y;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("AABB_position", m_position);
        }
    }

    void PhysicsComponent::setSize(sf::Vector2u& size)
    {
        m_size = size;
        m_AABB.width = m_size.x;
        m_AABB.height = m_size.y;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("AABB_size", m_size);
        }
    }

    void PhysicsComponent::setVelocity(sf::Vector2f& velocity)
    {
        m_velocity = velocity;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("physics_velocity", m_velocity);
        }
    }

    void PhysicsComponent::update(const float dt)
    {
        m_velocity += m_acceleration;
        m_position += m_velocity;
    }
}