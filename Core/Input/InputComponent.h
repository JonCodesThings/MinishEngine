#ifndef MINISH_INPUTCOMPONENT_H
#define MINISH_INPUTCOMPONENT_H

#include <SFML/System/Vector2.hpp>

#include "Core/Entity/Component.h"

namespace minish
{
    class InputComponent : public Component
    {
        public:
            virtual ~InputComponent();
    };
}

#endif