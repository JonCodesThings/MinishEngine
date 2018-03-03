#ifndef MINISH_AABB_H
#define MINISH_AABB_H

#include <SFML/Graphics/Rect.hpp>

namespace minish
{
    typedef sf::FloatRect AABB;

    class Collision
    {
        static bool getAABBCollision(AABB& box1, AABB& box2);
    };
}

#endif