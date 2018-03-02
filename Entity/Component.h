#ifndef MINISH_COMPONENT_H
#define MINISH_COMPONENT_H

namespace sf
{
	class RenderWindow;
}

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

			/*!
        	\brief Virtual function called to render a component. Empty by default.
        	*/
			virtual void render(sf::RenderWindow* hwnd) {};

			/*!
        	\brief Pure virtual function called when a component is updated.
        	*/
			virtual void update(const float dt) = 0;
		private:
			/*!
        	\brief Sets the entity the component is attached to.
        	*/
			void setEntity(Entity* entity);

			Entity* m_entity = nullptr;
	};
}

#endif