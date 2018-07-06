#include "State.h"

namespace minish
{
    State::State(Frame& frame, const std::string& id, InputManager& input) : m_frame(&frame), m_input(&input), m_id(id)
    {}

    State::~State()
    {
    }

    const std::string& State::getID() const
    {
        return m_id;
    }
}