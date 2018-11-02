#include "Entity.h"

namespace minish
{
    unsigned int Entity::ENTITY_COUNT = 0;

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
                component_->setEntity(*this);
                return;
            }
        }
        return;
    }

    const unsigned int Entity::getID() const
    {
        return m_id;
    }

#ifdef MINISH_EXPERIMENTAL
    DataComponent& Entity::getDataComponent()
    {
        return m_data;
    }
#endif

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