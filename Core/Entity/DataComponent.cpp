#include "DataComponent.h"

namespace minish
{
    Data DataComponent::getData(std::string data_id)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            Data data;
            data.custom_data = nullptr;
            return data;
        }
        else
        {
            return m_data[data_id];
        }
    }
}