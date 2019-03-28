#include "Entity.h"

namespace minish
{
    unsigned int Entity::ENTITY_COUNT = 0;

    Entity::Entity() : m_transform(sf::Transform::Identity), m_rotation(0.0f), m_position(0.0f, 0.0f), m_scale(1.0f, 1.0f), m_id(ENTITY_COUNT)
    {
        ENTITY_COUNT++;
    }

    void Entity::addComponent(Component& component)
    {
        for (auto component_ : m_components)
        {
            if (component_ == &component)
                return;
        }
        for (auto& component_ : m_components)
        {
            if (component_ == nullptr)
            {
                component_ = &component;
                component_->setEntity(*this);
                return;
            }
        }
        return;
    }

	void Entity::addChild(Entity& entity)
	{
		for (auto child_ : m_children)
		{
			if (child_ == &entity)
				return;
		}

		for (auto& child_ : m_children)
		{
			if (child_ == nullptr)
			{
				child_ = &entity;
				child_->setParent(*this);
				return;
			}
		}
	}

	const unsigned int Entity::getID() const
    {
        return m_id;
    }

	const sf::Vector2f & Entity::getPosition() const
	{
		return m_position;
	}

	const float Entity::getRotation() const
	{
		return m_rotation;
	}

	const sf::Vector2f & Entity::getScale() const
	{
		return m_scale;
	}

	const sf::Transform & Entity::getTransform() const
	{
		return m_transform;
	}

	void Entity::removeChild(Entity& entity)
	{
		for (auto& child_ : m_children)
		{
			if (child_ == &entity)
			{
				child_ = nullptr;
				return;
			}
		}
	}

	void Entity::recalculateTransform()
	{
		m_transform = sf::Transform::Identity;

		if (m_parent)
			m_transform *= m_parent->getTransform();

		m_transform = m_transform.scale(m_scale).rotate(m_rotation, m_position).translate(m_position);

		for (auto& child_ : m_children)
		{
			if (child_ != nullptr)
				child_->recalculateTransform();
		}
	}

	void Entity::resetParent()
	{
		m_parent = nullptr;
	}

	void Entity::setParent(Entity& entity)
	{
		m_parent = &entity;
		recalculateTransform();
	}

	void Entity::setPosition(const sf::Vector2f& position)
	{
		m_position = position;
		recalculateTransform();
	}

	void Entity::setRotation(const float rotation)
	{
		m_rotation = rotation;
		recalculateTransform();
	}

	void Entity::setScale(const sf::Vector2f& scale)
	{
		m_scale = scale;
		recalculateTransform();
	}

#ifdef MINISH_EXPERIMENTAL
    DataComponent& Entity::getDataComponent()
    {
        return m_data;
    }
#endif

    void Entity::removeComponent(Component& component)
    {
        for (auto& component_ : m_components)
        {
            if (component_ == &component)
            {
                component_ = nullptr;
                return;
            }
        }
    }
}