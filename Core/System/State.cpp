#include "State.h"

namespace minish
{
    State::State(Frame& frame, std::string id, InputManager& input) : m_frame(&frame), m_input(&input), m_id(id)
    {}

    State::~State()
    {
    }

    std::string State::getID()
    {
        return m_id;
    }
}