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

    void DataComponent::setData(std::string data_id, Data& data)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            m_data.insert(std::pair<std::string, Data>(data_id, data));
        }
        else if (it != m_data.end())
        {
            m_data[data_id] = data;
        }
    }
}