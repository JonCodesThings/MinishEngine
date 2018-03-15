#include "Subsystem.h"

namespace minish
{
    bool Subsystem::getUpdateFlag()
    {
        return m_updated;
    }

    void Subsystem::toggleUpdateFlag()
    {
        m_updated = !m_updated;
    }
}