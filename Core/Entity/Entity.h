#ifndef MINISH_ENTITY_H
#define MINISH_ENTITY_H

#include "Component.h"

#ifdef MINISH_EXPERIMENTAL
#include "DataComponent.h"
#endif

namespace minish
{
    /*!
    * \brief Class to represent Entities with Components.
    * \author Jonathan Duncanson
    */
    class Entity
    {
		friend class Component;
        public:
            Entity();
            /*!
        	\brief Class member that adds a component to the entity.
        	*/
            void addComponent(Component& component);

			void addChild(Entity& entity);

            const unsigned int getID() const;

			const sf::Vector2f& getPosition() const;

			const float getRotation() const;

			const sf::Vector2f& getScale() const;

			const sf::Transform& getTransform() const;

            /*!
        	\brief Class member that removes a component from the entity.
        	*/
            void removeComponent(Component& component);

			void removeChild(Entity& entity);

			void setPosition(const sf::Vector2f& position);

			void setRotation(const float rotation);

			void setScale(const sf::Vector2f& scale);
        private:
			void recalculateTransform();

			void resetParent();

			void setParent(Entity& entity);

            /*!
        	\brief Array of pointers to components associated with the entity.
        	*/
            Component* m_components[8] { nullptr };

			Entity* m_children[8] { nullptr };

			Entity* m_parent = nullptr;

			sf::Transform m_transform;

			/*!
			\brief The rotation of the entity.
			*/
			float m_rotation;

			/*!
			\brief The position and scale factor of the entity.
			*/
			sf::Vector2f m_position, m_scale;

            unsigned int m_id;

            static unsigned int ENTITY_COUNT;
    };

    #ifdef MINISH_EXPERIMENTAL
    class Entity
    {
        public:
            Entity();
            /*!
        	\brief Class member that adds a component to the entity.
        	*/
            void addComponent(Component* component);

            DataComponent& getDataComponent();

            const unsigned int getID() const;

            /*!
        	\brief Class member that removes a component from the entity.
        	*/
            void removeComponent(Component* component);
        private:
            /*!
        	\brief Array of pointers to components associated with the entity.
        	*/
            Component* m_components[4] { nullptr };
            DataComponent m_data;
            unsigned int m_id;

            static unsigned int ENTITY_COUNT;
    };
    #endif
}

#endif