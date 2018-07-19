#include "PhysicsComponent.h"

#include "Core/Entity/Entity.h"

namespace minish
{
    const AABB& PhysicsComponent::getAABB() const
    {
        return m_AABB;
    }

    const sf::Vector2f& PhysicsComponent::getAcceleration() const
    {
        return m_acceleration;
    }

    const sf::Vector2f& PhysicsComponent::getPosition() const
    {
        return m_position;
    }

    const sf::Vector2u& PhysicsComponent::getSize() const
    {
        return m_size;
    }

    const sf::Vector2f& PhysicsComponent::getVelocity() const
    {
        return m_velocity;
    }

    void PhysicsComponent::setAABB(const AABB& aabb)
    {
        m_AABB = aabb;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("AABB", m_AABB);
        }
    }

    void PhysicsComponent::setAcceleration(const sf::Vector2f& acceleration)
    {
        m_acceleration = acceleration;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("physics_acceleration", m_acceleration);
        }
    }

    void PhysicsComponent::setPosition(const sf::Vector2f& position)
    {
        m_position = position;
        m_AABB.left = m_position.x;
        m_AABB.top = m_position.y;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("AABB_position", m_position);
        }
    }

    void PhysicsComponent::setSize(const sf::Vector2u& size)
    {
        m_size = size;
        m_AABB.width = m_size.x;
        m_AABB.height = m_size.y;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("AABB_size", m_size);
        }
    }

    void PhysicsComponent::setVelocity(const sf::Vector2f& velocity)
    {
        m_velocity = velocity;
        if (getEntity() != nullptr)
        {
            getEntity()->getDataComponent().setData("physics_velocity", m_velocity);
        }
    }

    void PhysicsComponent::update(const float dt)
    {
        m_velocity += m_acceleration * dt;
        m_position += m_velocity * dt;
        m_AABB.left = m_position.x;
        m_AABB.top = m_position.y;
    }

    void PhysicsComponent::setEntity(Entity& entity)
    {
        Component::setEntity(entity);
        getEntity()->getDataComponent().registerData("AABB", m_AABB);
        getEntity()->getDataComponent().registerData("AABB_position", m_position);
        getEntity()->getDataComponent().registerData("AABB_size", m_size);
        getEntity()->getDataComponent().registerData("physics_acceleration", m_acceleration);
        getEntity()->getDataComponent().registerData("physics_velocity", m_velocity);
    }
}