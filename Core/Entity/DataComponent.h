#ifndef MINISH_DATACOMPONENT_H
#define MINISH_DATACOMPONENT_H

#include <unordered_map>

#include "Component.h"

namespace minish
{
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
            void* getData(std::string data_id);

            /*!
        	\brief Class member that sets the data value in the requested id.
        	*/
            void setData(std::string data_id, void* data);

            /*!
        	\brief Dummy class member that does nothing.
        	*/
            void update(const float dt) {};
        private:
            /*!
        	\brief Unordered map to store the data in.
        	*/
            std::unordered_map<std::string, void*> m_data;
    };
}

#endif