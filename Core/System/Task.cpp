#include "Task.h"

namespace minish
{
    TASK_STATE Task::getTaskState()
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