#include "Subsystem.h"

#include <thread>

namespace minish
{
    void Subsystem::addDependency(Subsystem& dependency)
    {
        m_dependencies.insert(&dependency);
    }

    SUBSYSTEM_STATE Subsystem::getSubsystemState()
    {
        return m_state;
    }

    void Subsystem::removeDependency(Subsystem& dependency)
    {
        m_dependencies.erase(&dependency);
    }

    void Subsystem::resetSubsystemState()
    {
        m_state = SUBSYSTEM_STATE::NOT_UPDATED;
    }

    void Subsystem::update(const float dt)
    {
        m_state = SUBSYSTEM_STATE::UPDATING;
        for (auto dependency : m_dependencies)
        {
            do 
            {
                std::this_thread::sleep_for(std::chrono::microseconds(10));
            } while (dependency->getSubsystemState() != SUBSYSTEM_STATE::NOT_UPDATED);
        }
        updateSubsystem(dt);
        m_state = SUBSYSTEM_STATE::UPDATED;
    }
}