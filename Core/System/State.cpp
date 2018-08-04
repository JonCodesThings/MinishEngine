#include "State.h"
#include "Application.h"
#include "StateManager.h"

namespace minish
{
    State::State(ApplicationSystem& application_system, const std::string& id) : m_application_system(application_system), m_id(id), m_state_manager(nullptr)
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

    void State::resizeApplicationWindow(const sf::Vector2u& window_dimensions)
    {
        m_application->resizeWindow(window_dimensions);
    }

    void State::setStateManager(StateManager& state_manager)
    {
        m_state_manager = &state_manager;
        m_application = &(m_state_manager->getApplication());
    }
}