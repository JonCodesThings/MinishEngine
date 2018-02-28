#ifndef MINISH_COMPONENT_H
#define MINISH_COMPONENT_H

namespace minish
{
	class Component
	{
		virtual ~Component();

		virtual void update(const float dt) = 0;
	};
}

#endif