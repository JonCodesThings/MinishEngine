#ifndef MINISH_STATEMANAGER_H
#define MINISH_STATEMANAGER_H

#include <string>
#include <vector>

namespace sf
{
    class RenderWindow;
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
            \brief Class method that adds a state to the manager.
            */
            void addState(State& state);

            /*!
            \brief Class method that changes the current state.
            */
            void changeState(std::string& id);

            /*!
            \brief Class method that removes a state from the manager.
            */
            void removeState(std::string& id);

            /*!
            \brief Renders the current state.
            */
            void render();

            /*!
            \brief Updates the current state.
            */
            void update(const float dt);
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