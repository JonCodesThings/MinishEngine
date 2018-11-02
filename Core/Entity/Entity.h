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
        public:
            Entity();
            /*!
        	\brief Class member that adds a component to the entity.
        	*/
            void addComponent(Component* component);

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