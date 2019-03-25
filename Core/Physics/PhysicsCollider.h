#ifndef MINISHENGINE_PHYSICSCOLLIDER_H
#define MINISHENGINE_PHYSICSCOLLIDER_H

#include <vector>

#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>

#include <Core/Entity/Component.h>

namespace minish
{
	class PhysicsCollider : public Component
	{
		friend class PhysicsEnvironment;
	public:
		PhysicsCollider();
		virtual ~PhysicsCollider();
		const std::vector<sf::Vector2f>& getPointList() const;
		const std::vector<sf::Vector2f>& getTransformedPointList() const;
		void setCollisionCallback(void (*callback)());
		void transformPoints(const sf::Transform& transform);
		void update(const float dt) {}
	protected:
		void addPoint(const sf::Vector2f& point);
		void removePoint(const sf::Vector2f& point);
	private:
		std::vector<sf::Vector2f> m_points;
		std::vector<sf::Vector2f> m_transformed_points;
		void (*m_collision_callback)();
	};
}

#endif