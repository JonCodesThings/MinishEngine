#include "State.h"
#include "StateManager.h"

namespace minish
{
    State::State(Frame& frame, const std::string& id, InputManager& input) : m_frame(&frame), m_input(&input), m_id(id), m_state_manager(nullptr)
    {}

    State::~State()
    {
    }

    const std::string& State::getID() const
    {
        return m_id;
    }

    void State::changeManagerState(const std::string& id)
    {
        m_state_manager->changeState(id);
    }

    void State::setStateManager(StateManager& state_manager)
    {
        m_state_manager = &state_manager;
    }
}