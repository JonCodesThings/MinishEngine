#ifndef MINISH_ENTITY_H
#define MINISH_ENTITY_H

#include "Component.h"

namespace minish
{
    class Entity
    {
        public:
            void addComponent(Component* component);
            void removeComponent(Component* component);
            void render(sf::RenderWindow* hwnd);
            void update(const float dt);
        private:
            Component* m_components[4] { nullptr };
    };
}

#endif