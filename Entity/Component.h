#ifndef MINISH_COMPONENT_H
#define MINISH_COMPONENT_H

namespace minish
{
	/*!
    * \brief Abstract class for components.
    * \author Jonathan Duncanson
    */
	class Component
	{
		/*!
        \brief Virtual destructor for abstract class.
        */
		virtual ~Component();

		/*!
        \brief Pure virtual function called when a component is updated.
        */
		virtual void update(const float dt) = 0;
	};
}

#endif