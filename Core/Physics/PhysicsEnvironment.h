#ifndef MINISHENGINE_PHYSICSENVIRONMENT_H
#define MINISHENGINE_PHYSICSENVIRONMENT_H

#include <vector>

#include <SFML/System/Vector2.hpp>

#include "PhysicsBody.h"

namespace minish
{
	class PhysicsEnvironment
	{
	public:
		PhysicsEnvironment(const sf::Vector2f& gravity = sf::Vector2f(0.0f, 0.0f));
		~PhysicsEnvironment();
		bool checkCollision(const PhysicsCollider& a, const PhysicsCollider& b);
		PhysicsBody* registerBody(sf::Vector2f body_position = sf::Vector2f(0.0f, 0.0f));
		void unregisterBody(PhysicsBody* body);
		void update(const float dt);
	private:
		bool checkAxes(const std::vector<sf::Vector2f>& axes, const std::vector<sf::Vector2f>& a_points, const std::vector<sf::Vector2f>& b_points);
		bool checkOverlaps(const sf::Vector2f& a, const sf::Vector2f& b);
		void getAxes(const std::vector<sf::Vector2f>& points, std::vector<sf::Vector2f>& axes_vec, unsigned int axes);
		sf::Vector2f projectPointsToAxis(const sf::Vector2f& axis, const std::vector<sf::Vector2f>& points);
	

		sf::Vector2f m_gravity;
		std::vector<PhysicsBody> m_bodies;
	};
}

#endif