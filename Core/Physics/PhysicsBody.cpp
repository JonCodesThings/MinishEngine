#include "PhysicsBody.h"

namespace minish
{
	PhysicsBody::PhysicsBody(const sf::Vector2f& position, PhysicsBodyType type) : m_acceleration(0.0f, 0.0f), m_collider(nullptr), m_position(position), m_rotation(0.0f), m_transform(sf::Transform::Identity), m_update_flag(true), m_velocity(0.0f, 0.0f), m_type(type)
	{}

	PhysicsBody::~PhysicsBody()
	{
	}

	void PhysicsBody::attachCollider(PhysicsCollider * const collider)
	{
		m_collider = collider;
	}

	void PhysicsBody::detatchCollider(PhysicsCollider * const collider)
	{
		if (m_collider == collider)
			m_collider = nullptr;
	}

	const sf::Vector2f& PhysicsBody::getAcceleration() const
	{
		return m_acceleration;
	}

	const PhysicsCollider* const PhysicsBody::getCollider() const
	{
		return m_collider;
	}

	const sf::Vector2f & PhysicsBody::getPosition() const
	{
		return m_position;
	}

	const float PhysicsBody::getRotation() const
	{
		return m_rotation;
	}

	const sf::Transform & PhysicsBody::getTransform() const
	{
		return m_transform;
	}

	const sf::Vector2f & PhysicsBody::getVelocity() const
	{
		return m_velocity;
	}

	void PhysicsBody::setAcceleration(const sf::Vector2f& acceleration)
	{
		m_acceleration = acceleration;
		m_update_flag = true;
	}

	void PhysicsBody::setPosition(const sf::Vector2f& position)
	{
		m_position = position;
		m_update_flag = true;
	}

	void PhysicsBody::setRotation(const float rotation)
	{
		m_rotation = rotation;
		m_update_flag = true;
	}

	void PhysicsBody::setVelocity(const sf::Vector2f& velocity)
	{
		m_velocity = velocity;
		m_update_flag = true;
	}

	void PhysicsBody::update(const float dt)
	{
		if (m_acceleration.x != 0.0f || m_acceleration.y != 0.0f)
			m_velocity += m_acceleration * dt;

		if (m_velocity.x != 0.0f || m_velocity.y != 0.0f)
			m_position += m_velocity * dt;
			

		if (m_velocity != sf::Vector2f(0.0f, 0.0f) && m_type != PhysicsBodyType::STATIC)
			m_update_flag = true;

		if (m_update_flag)
		{
			m_transform = sf::Transform::Identity;
			m_transform.rotate(m_rotation, m_position);
			m_transform.translate(m_position);

			if (m_collider)
				m_collider->transformPoints(m_transform);

			m_update_flag = false;
		}
	}


}