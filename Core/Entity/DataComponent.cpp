#include "DataComponent.h"

namespace minish
{
    const void* const DataComponent::getData(std::string data_id)
    {
        std::unordered_map<std::string, void*>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            return nullptr;
        }
        else
        {
            return m_data[data_id];
        }
    }
}