#ifndef MINISH_UIBUTTON_H
#define MINISH_UIBUTTON_H

#include "Core/Physics/AABB.h"
#include "UIElement.h"

namespace minish
{
    class Action;

    class UIButton : public UIElement
    {
        public:
            const AABB& getAABB();
            void bindAction(Action& action);
            void onAction();
            void unbindAction();
        private:
            AABB m_AABB;
            Action* m_action = nullptr;
    };
}

#endif