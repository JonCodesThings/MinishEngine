#include "DataComponent.h"

namespace minish
{
    void* DataComponent::getData(std::string data_id)
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

    void DataComponent::setData(std::string data_id, void* data)
    {
        std::unordered_map<std::string, void*>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            m_data.insert(std::pair<std::string, void*>(data_id, data));
        }
        else if (it != m_data.end())
        {
            m_data[data_id] = data;
        }
    }
}