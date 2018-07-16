#include "DataComponent.h"

namespace minish
{
    const void* const DataComponent::getData(const std::string& data_id) const
    {
        std::unordered_map<std::string, void*>::const_iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            return nullptr;
        }
        else
        {
            return m_data.at(data_id);
        }
    }
}