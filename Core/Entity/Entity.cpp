#include "Entity.h"

namespace minish
{
    void Entity::addComponent(Component* component)
    {
        for (auto component_ : m_components)
        {
            if (component_ == component)
            {
                return;
            }
        }
        for (auto component_ : m_components)
        {
            if (component_ == nullptr)
            {
                component_ = component;
                return;
            }
        }
        return;
    }

    void Entity::removeComponent(Component* component)
    {
        for (auto component_ : m_components)
        {
            if (component_ == component)
            {
                component_ = nullptr;
                return;
            }
        }
    }

    void Entity::render(sf::RenderWindow* hwnd)
    {
        for (auto& component_ : m_components)
        {
            component_->render(hwnd);
        }
    }

    void Entity::update(const float dt)
    {
        for (auto& component_ : m_components)
        {
            component_->update(dt);
        }
    }
}