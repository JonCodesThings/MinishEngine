#include "PhysicsEnvironment.h"

#include <SFML/System/Vector2.hpp>

namespace minish
{
	PhysicsEnvironment::PhysicsEnvironment(const sf::Vector2f& gravity) : m_gravity(gravity)
	{}

	PhysicsEnvironment::~PhysicsEnvironment()
	{}

	PhysicsBody* PhysicsEnvironment::registerBody(sf::Vector2f body_position)
	{
		m_bodies.push_back(PhysicsBody(body_position));
		return &m_bodies.back();
	}

	void PhysicsEnvironment::unregisterBody(PhysicsBody* const body)
	{
		auto pos = m_bodies.end();
		for (auto it = m_bodies.begin(); it != m_bodies.end(); it++)
		{
			if (&(*it) == body)
			{
				pos = it;
				break;
			}
		}

		if (pos != m_bodies.end())
			m_bodies.erase(pos);

	}

	void PhysicsEnvironment::update(const float dt)
	{
		for (auto it = m_bodies.begin(); it != m_bodies.end(); it++)
		{
			(*it).update(dt);
		}
	}

	bool PhysicsEnvironment::checkAxes(const std::vector<sf::Vector2f>& axes, const std::vector<sf::Vector2f>& a_points, const std::vector<sf::Vector2f>& b_points)
	{
		for (auto it = axes.begin(); it != axes.end(); it++)
		{
			sf::Vector2f projA = projectPointsToAxis((*it), a_points);
			sf::Vector2f projB = projectPointsToAxis((*it), b_points);

			if (!checkOverlaps(projA, projB))
				return false;
		}

		return true;
	}

	bool PhysicsEnvironment::checkCollision(const PhysicsCollider& a, const PhysicsCollider& b)
	{
		std::vector<sf::Vector2f> a_axes;
		std::vector<sf::Vector2f> b_axes;

		a_axes.reserve(a.getPointList().size());
		b_axes.reserve(b.getPointList().size());
		
		getAxes(a_axes, a.getPointList().size());
		getAxes(b_axes, b.getPointList().size());

		if (!checkAxes(a_axes, a.getPointList(), b.getPointList()))
			return false;

		if (!checkAxes(b_axes, a.getPointList(), b.getPointList()))
			return false;

		if (a.m_collision_callback)
			a.m_collision_callback();

		if (b.m_collision_callback)
			b.m_collision_callback();

		return true;
	}

	bool PhysicsEnvironment::checkOverlaps(const sf::Vector2f& a, const sf::Vector2f& b)
	{
		if (a.y < b.x || b.y < a.x)
			return false;

		return false;
	}

	void PhysicsEnvironment::getAxes(std::vector<sf::Vector2f>& axes_vec, unsigned int axes)
	{
		for (unsigned int i = 0; i < axes; i++)
		{
			sf::Vector2f point1 = axes_vec[i];

			if (i + 1 == axes)
				i = 0;

			sf::Vector2f point2 = axes_vec[i];

			sf::Vector2f edge = point1 - point2;

			sf::Vector2f axis = (edge.x / edge.y) * sf::Vector2f(1.0f, 1.0f);

			axis.x /= axis.x;
			axis.y /= axis.y;

			axes_vec.push_back(axis);
		}
	}

	sf::Vector2f PhysicsEnvironment::projectPointsToAxis(const sf::Vector2f& axis, const std::vector<sf::Vector2f>& points)
	{
		float min = (axis.x * points[0].x) + (axis.y * points[0].y);
		float max = min;

		for (auto it = points.begin(); it != points.end(); it++)
		{
			float proj = (axis.x * (*it).x) + (axis.y * (*it).y);

			if (proj < min)
				min = proj;
			else if (proj > max)
				max = proj;
		}

		return sf::Vector2f(min, max);
	}
}

