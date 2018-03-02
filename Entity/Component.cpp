#include "Component.h"

namespace minish
{
	Component::~Component()
	{
	}

	void Component::setEntity(Entity* entity)
	{
		m_entity = entity;
	}
}