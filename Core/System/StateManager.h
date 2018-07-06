#ifndef MINISH_STATEMANAGER_H
#define MINISH_STATEMANAGER_H

#include <string>
#include <vector>

namespace sf
{
    class RenderTarget;
}

namespace minish
{
    class State;

    /*!
    * \brief State machine class to manage gamestate.
    * \author Jonathan Duncanson
    */
    class StateManager
    {
        public:
			/*!
			\brief Default constructor.
			*/
			StateManager();

            /*!
            \brief Class method that adds a state to the manager.
            */
            void addState(State& state);

            /*!
            \brief Class method that changes the current state.
            */
            void changeState(const std::string& id);

            /*!
            \brief Class method that removes a state from the manager.
            */
            void removeState(const std::string& id);

            /*!
            \brief Renders the current state.
            */
            void render();

            /*!
            \brief Updates the current state.
            */
            const bool update(const float dt);
        private:
            /*!
            \brief Vector of pointers to different states.
            */
            std::vector<State*> m_states;

            /*!
            \brief Pointer to the current state.
            */
            State* m_current_state = nullptr;
    };
}

#endif