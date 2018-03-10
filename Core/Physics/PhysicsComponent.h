#ifndef MINISH_PHYSICSCOMPONENT_H
#define MINISH_PHYSICSCOMPONENT_H

#include "Core/Entity/Component.h"
#include "AABB.h"

namespace minish
{
    /*!
    * \brief Class used for entities that require collision detection.
    * \author Jonathan Duncanson
    */
    class PhysicsComponent : public Component
    {
        public:
            /*!
            \brief Virtual destructor.
            */
            virtual ~PhysicsComponent();

            /*!
            \brief Class method that returns the AABB.
            */
            const AABB& getAABB();

            /*!
            \brief Class method that sets the AABB.
            */
            void setAABB(AABB& aabb);

            /*!
            \brief Class method that sets the position of the AABB.
            */
            void setPosition(sf::Vector2f& position);

            /*!
            \brief Class method that sets the size of the AABB.
            */
            void setSize(sf::Vector2u& size);
        protected:
            /*!
            \brief AABB rect.
            */
            AABB m_AABB;
    };
}

#endif