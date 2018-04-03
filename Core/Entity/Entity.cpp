#include "Entity.h"

namespace minish
{
    Entity::Entity() : m_id(ENTITY_COUNT)
    {
        ENTITY_COUNT++;
    }

    void Entity::addComponent(Component* component)
    {
        for (auto component_ : m_components)
        {
            if (component_ == component)
            {
                return;
            }
        }
        for (auto& component_ : m_components)
        {
            if (component_ == nullptr)
            {
                component_ = component;
                return;
            }
        }
        return;
    }

    const unsigned int Entity::getID()
    {
        return m_id;
    }

    const DataComponent& Entity::getDataComponent()
    {
        return m_data;
    }

    void Entity::removeComponent(Component* component)
    {
        for (auto& component_ : m_components)
        {
            if (component_ == component)
            {
                component_ = nullptr;
                return;
            }
        }
    }
}