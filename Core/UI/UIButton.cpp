#include "UIButton.h"

#include "Core/System/Action.h"

namespace minish
{
    const AABB& UIButton::getAABB()
    {
        return m_AABB;
    }

    void UIButton::bindAction(Action& action)
    {
        if (m_action)
            unbindAction();

        m_action = &action;
    }

    void UIButton::onAction()
    {
        if (m_action)
            m_action->onAction();
    }

    void UIButton::unbindAction()
    {
        m_action = nullptr;
    }
}