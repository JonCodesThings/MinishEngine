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
            Data getData(std::string data_id);

            /*!
        	\brief Class member that sets the data value in the requested id.
        	*/
            void setData(std::string data_id, Data& data);

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
}

#endif