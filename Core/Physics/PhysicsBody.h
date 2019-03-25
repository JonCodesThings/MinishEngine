#ifndef MINISHENGINE_PHYSICSBODY_H
#define MINISHENGINE_PHYSICSBODY_H

#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>

#include "Core/Entity/Entity.h"

#include "PhysicsCollider.h"

namespace minish
{
	enum class PhysicsBodyType
	{
		DYNAMIC,
		STATIC
	};

	class PhysicsBody : public Component
	{
	public:
		PhysicsBody(const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f), PhysicsBodyType type = PhysicsBodyType::DYNAMIC);
		~PhysicsBody();

		//attach/detatch colliders
		void attachCollider(PhysicsCollider* const collider);
		void detatchCollider(PhysicsCollider* const collider);

		//getters
		const sf::Vector2f& getAcceleration() const;
		const PhysicsBodyType& getBodyType() const;
		const PhysicsCollider* const getCollider() const;
		const sf::Vector2f& getPosition() const;
		const float getRotation() const;
		const sf::Transform& getTransform() const;
		const sf::Vector2f& getVelocity() const;

		//setters
		void setAcceleration(const sf::Vector2f& acceleration);
		void setPosition(const sf::Vector2f& position);
		void setRotation(const float rotation);
		void setVelocity(const sf::Vector2f& velocity);

		//update
		void update(const float dt);
	private:
		sf::Transform m_transform;
		PhysicsCollider* m_collider;
		sf::Vector2f m_acceleration, m_position, m_velocity;
		float m_rotation;
		bool m_update_flag;
		PhysicsBodyType m_type;
	};
}

#endif