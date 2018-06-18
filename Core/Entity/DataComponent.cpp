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

    template<class T>
    void DataComponent::setData(std::string data_id, T& data)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            minish::Data new_data;
            new_data.custom_data = (void*)&data;
            m_data.insert(std::pair<std::string, Data>(data_id, data));
        }
        else if (it != m_data.end())
        {
            m_data[data_id].custom_data = (void*)&data;
        }
    }

    template<>
    void DataComponent::setData(std::string data_id, int& data)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            minish::Data new_data;
            new_data.integer = data;
            m_data.insert(std::pair<std::string, Data>(data_id, new_data)); 
        }
        else if (it != m_data.end())
        {
            m_data[data_id].integer = data;
        }
    }

    template<>
    void DataComponent::setData(std::string data_id, float& data)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            minish::Data new_data;
            new_data.floating_point = data;
            m_data.insert(std::pair<std::string, Data>(data_id, new_data)); 
        }
        else if (it != m_data.end())
        {
            m_data[data_id].floating_point = data;
        }
    }

    template<>
    void DataComponent::setData(std::string data_id, double& data)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            minish::Data new_data;
            new_data.double_precision = data;
            m_data.insert(std::pair<std::string, Data>(data_id, new_data)); 
        }
        else if (it != m_data.end())
        {
            m_data[data_id].double_precision = data;
        }
    }

    template<>
    void DataComponent::setData(std::string data_id, bool& data)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            minish::Data new_data;
            new_data.boolean = data;
            m_data.insert(std::pair<std::string, Data>(data_id, new_data)); 
        }
        else if (it != m_data.end())
        {
            m_data[data_id].boolean = data;
        }
    }

    template<>
    void DataComponent::setData(std::string data_id, char& data)
    {
        std::unordered_map<std::string, Data>::iterator it = m_data.find(data_id);

        if (it == m_data.end())
        {
            minish::Data new_data;
            new_data.character = data;
            m_data.insert(std::pair<std::string, Data>(data_id, new_data)); 
        }
        else if (it != m_data.end())
        {
            m_data[data_id].character = data;
        }
    }
}