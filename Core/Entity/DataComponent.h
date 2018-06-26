#ifndef MINISH_DATACOMPONENT_H
#define MINISH_DATACOMPONENT_H

#include <string>
#include <unordered_map>

#include "Component.h"

namespace minish
{
    union Data
    {
        int integer;
        float floating_point;
        double double_precision;
        bool boolean;
        char character;
        void* custom_data;
    };


    /*!
    * \brief Class to store Entity data.
    * \author Jonathan Duncanson
    */
    class DataComponent : public Component
    {
        public:
            /*!
        	\brief Class member that returns data from the component. Returns nullptr if there is no data for the requested id.
        	*/
            const Data& getData(std::string data_id);

            /*!
            \brief Class member that registers the location of data associated with the component.
            */
            template <class T>
            void registerData(std::string, T& data);

            /*!
        	\brief Class member that sets the data value in the requested id.
        	*/
            template <class T>
            void setData(std::string data_id, T& data);

            /*!
        	\brief Dummy class member that does nothing.
        	*/
            void update(const float dt) {};
        private:
            /*!
        	\brief Unordered map to store the data in.
        	*/
            std::unordered_map<std::string, Data> m_data;
    };

    template<>
    void DataComponent::setData<int>(std::string data_id, int& data);

    template<>
    void DataComponent::setData<float>(std::string data_id, float& data);

    template<>
    void DataComponent::setData<double>(std::string data_id, double& data);

    template<>
    void DataComponent::setData<bool>(std::string data_id, bool& data);

    template<>
    void DataComponent::setData<char>(std::string data_id, char& data);
}

#include "DataComponent.tmpl"

#endif