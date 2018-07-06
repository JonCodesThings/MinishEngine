#ifndef MINISH_DATACOMPONENT_H
#define MINISH_DATACOMPONENT_H

#include <string>
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
            const void* const getData(std::string data_id) const;

            /*!
            \brief Class member that registers the location of data associated with the component.
            */
            template <class T>
            bool registerData(std::string data_id, T& data);

            /*!
        	\brief Class member that sets the data value in the requested id.
        	*/
            template <class T>
            bool setData(std::string data_id, T& data);

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

#include "DataComponent.tmpl"

#endif