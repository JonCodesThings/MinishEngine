#include "Task.h"

#include "Core/System/Application.h"

namespace minish
{
    const TASK_STATE& Task::getTaskState() const
    {
        return m_state;
    }

    void Task::resetTaskState()
    {
        m_state = TASK_STATE::NOT_UPDATED;
    }

    void Task::update(const float dt)
    {
        m_state = TASK_STATE::UPDATING;
        updateTask(dt);
        if (m_state != TASK_STATE::COMPLETED || m_state != TASK_STATE::ABORTED || m_state != TASK_STATE::FAILED)
            m_state = TASK_STATE::UPDATED;
    }
}