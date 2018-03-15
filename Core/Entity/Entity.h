#ifndef MINISH_ENTITY_H
#define MINISH_ENTITY_H

#include "Component.h"
#include "DataComponent.h"

namespace minish
{
    /*!
    * \brief Class to represent Entities with Components.
    * \author Jonathan Duncanson
    */
    class Entity
    {
        public:
            /*!
        	\brief Class member that adds a component to the entity.
        	*/
            void addComponent(Component* component);

            /*!
        	\brief Class member that removes a component from the entity.
        	*/
            void removeComponent(Component* component);

            /*!
        	\brief Class member that renders all components associated with the entity.
        	*/
            void render(sf::RenderWindow* hwnd);

            /*!
        	\brief Class member that updates all components associated with the entity.
        	*/
            void update(const float dt);
        private:
            /*!
        	\brief Array of pointers to components associated with the entity.
        	*/
            Component* m_components[4] { nullptr };
            DataComponent m_data;
    };
}

#endif