#ifndef MINISH_INPUTCOMPONENT_H
#define MINISH_INPUTCOMPONENT_H

#include <SFML/System/Vector2.hpp>

#include "Entity/Component.h"

namespace minish
{
    class InputComponent : public Component
    {
        virtual ~InputComponent();
    };
}

#endif