#include "Component.h"

#include "Entity.h"

namespace minish
{
	Component::~Component()
	{
	}

	Entity* const Component::getEntity()
	{
		return m_entity;
	}

	void Component::setEntity(Entity* entity)
	{
		m_entity = entity;
	}
}