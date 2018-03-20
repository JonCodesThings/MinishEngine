#ifndef MINISH_AABB_H
#define MINISH_AABB_H

#include <SFML/Graphics/Rect.hpp>

namespace minish
{
    /*!
    \brief Typedef to make collision rectangles easier to distinguish from other rectangles.
    */
    typedef sf::FloatRect AABB;

    class Collision
    {	
	public:
        /*!
        \brief Static class method that checks if there is a collision between two AABBs.
        */
        static bool getAABBCollision(const AABB& box1, const AABB& box2);

		static bool getAABBPointCollision(const sf::Vector2f& point, const AABB& box);
    };
}

#endif