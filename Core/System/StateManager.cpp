#include "StateManager.h"
#include "State.h"

namespace minish
{
	StateManager::StateManager() : m_current_state(nullptr)
	{

	}

    void StateManager::addState(State& state)
    {
        for (auto& state_ : m_states)
        {
            if (state_->getID() == state.getID())
            {
                return;
            }
        }

        m_states.push_back(&state);
        
        state.startup();

        if (m_current_state == nullptr)
        {
            m_current_state = &state;
            m_current_state->init();
        }
    }

    void StateManager::changeState(const std::string& id)
    { 
        for (auto& state_ : m_states)
        {
            if (state_->getID() == id)
            {
                if (m_current_state)
                {
                    m_current_state->deinit();
                    m_current_state = state_;
                    m_current_state->init();
                    return;
                }
                else
                {
                    m_current_state = state_;
                    m_current_state->init();
                    return;
                }
            }
        }
    }

    void StateManager::removeState(const std::string& id)
    {
        for (auto m_states_iter = m_states.begin(); m_states_iter != m_states.end(); m_states_iter++)
        {
            if ((*m_states_iter)->getID() == id)
            {
                (*m_states_iter)->shutdown();
                m_states.erase(m_states_iter);
                return;
            }
        }
    }

    void StateManager::render()
    {
        if (m_current_state)
        {
            m_current_state->render();
        }
    }

    const bool StateManager::update(const float dt)
    {
        if (m_current_state)
        {
            return m_current_state->update(dt);
        }
        return false;
    }
}