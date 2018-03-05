#include "AABB.h"

namespace minish
{
    bool Collision::getAABBCollision(AABB& box1, AABB& box2)
    {
        if (box1.left + box1.width < box2.left)
            return false;
        if (box1.left > box2.left + box2.width)
            return false;
        if (box1.top + box1.height < box2.top)
            return false;
        if (box1.top > box2.top + box2.height)
            return false;

        return true;
    }
}