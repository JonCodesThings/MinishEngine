#ifndef MINISH_DATACOMPONENT_H
#define MINISH_DATACOMPONENT_H

#include <unordered_map>

#include "Component.h"

namespace minish
{
    class DataComponent : public Component
    {
        public:
            void* getData(std::string data_id);
            void setData(std::string data_id, void* data);
            void update(const float dt) {};
        private:
            std::unordered_map<std::string, void*> m_data;
    };
}

#endif