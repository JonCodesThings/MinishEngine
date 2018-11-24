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
    class Application;
    class State;

    /*!
    * \brief State machine class to manage gamestate.
    * \author Jonathan Duncanson
    */
    class StateManager
    {
        public:
			/*!
			\brief Constructor.
			*/
			StateManager(Application& application);

            /*!
            \brief Class method that adds a state to the manager.
            */
            void addState(State& state);

            /*!
            \brief Class method that changes the current state.
            */
            void changeState(const std::string& id);

            /*!
            \brief Class method to return the reference to the base application.
            */
           Application& getApplication();

            /*!
            \brief Class method that removes a state from the manager.
            */
            void removeState(const std::string& id);

            /*!
            \brief Renders the current state.
            */
            void render(float update_difference);

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

            /*!
            \brief Pointer to the application.
            */
           Application& m_application;
    };
}

#endif