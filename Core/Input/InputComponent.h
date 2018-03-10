#ifndef MINISH_INPUTCOMPONENT_H
#define MINISH_INPUTCOMPONENT_H

#include "Core/Entity/Component.h"

namespace minish
{
    /*!
    * \brief Abstract class used for entities that require input.
    * \author Jonathan Duncanson
    */
    class InputComponent : public Component
    {
        public:
            /*!
            \brief Virtual destructor.
            */
            virtual ~InputComponent();
    };
}

#endif