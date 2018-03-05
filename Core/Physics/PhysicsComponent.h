#ifndef MINISH_PHYSICSCOMPONENT_H
#define MINISH_PHYSICSCOMPONENT_H

#include "Core/Entity/Component.h"
#include "AABB.h"

namespace minish
{
    class PhysicsComponent : public Component
    {
        public:
            virtual ~PhysicsComponent();
            const AABB& getAABB();
            void setAABB(AABB& aabb);
            void setPosition(sf::Vector2f& position);
            void setSize(sf::Vector2u& size);
        protected:
            AABB m_AABB;
    };
}

#endif