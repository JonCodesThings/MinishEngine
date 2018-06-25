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
            virtual ~PhysicsComponent() {};

            /*!
            \brief Class method that returns the AABB.
            */
            const AABB& getAABB();

            const sf::Vector2f& getAcceleration();

            const sf::Vector2f& getPosition();

            const sf::Vector2u& getSize();

            const sf::Vector2f& getVelocity();

            /*!
            \brief Class method that sets the AABB.
            */
            void setAABB(AABB& aabb);

            void setAcceleration(sf::Vector2f& acceleration);

            /*!
            \brief Class method that sets the position of the AABB.
            */
            void setPosition(sf::Vector2f& position);

            /*!
            \brief Class method that sets the size of the AABB.
            */
            void setSize(sf::Vector2u& size);

            void setVelocity(sf::Vector2f& velocity);

            virtual void update(const float dt);
        protected:
            /*!
            \brief AABB rect.
            */
            AABB m_AABB;

            sf::Vector2f m_acceleration, m_position, m_velocity;
            
            sf::Vector2u m_size;
        private:
            /*!
            \brief Override of base Component setEntity member function. Registers the component's data with the entity.
            */
            virtual void setEntity(Entity& entity);
    };
}

#endif