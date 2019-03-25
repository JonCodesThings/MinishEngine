#ifndef MINISH_COMPONENT_H
#define MINISH_COMPONENT_H

#include "Core/Graphics/Frame.h"

namespace minish
{
	class Entity;

	/*!
    * \brief Abstract class for components.
    * \author Jonathan Duncanson
    */
	class Component
	{
		friend class Entity;
		public:
			/*!
        	\brief Virtual destructor for abstract class.
        	*/
			virtual ~Component();

			Entity* const getEntity();
		protected:
			/*!
        	\brief Sets the entity the component is attached to.
        	*/
			virtual void setEntity(Entity& entity);
		private:
			/*!
        	\brief Pointer to the component's entity.
        	*/
			Entity* m_entity = nullptr;
	};
}

#endif