#ifndef MINISH_STATE_H
#define MINISH_STATE_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <Core/Graphics/Frame.h>
#include <Core/Input/InputManager.h>
#include <string>

namespace sf
{
    class RenderWindow;
}

namespace minish
{
    class StateManager;
    /*!
    * \brief Abstact class for gamestate management.
    * \author Jonathan Duncanson
    */
    class State
    {
        friend class StateManager;
        public:
            /*!
            \brief Default constructor, passes in reference to window and string id for state switching purposes.
            */
            State(minish::Frame& frame, const std::string& id, InputManager& input);

            /*!
            \brief Default destructor, calls shutdown class method to free resources.
            */
            virtual ~State();

            /*!
            \brief Returns the state's id.
            */
            const std::string& getID() const;

            /*!
            \brief Pure virtual class method used to initialise resources for the state.
            */
            virtual const bool init() = 0;

            /*!
            \brief Pure virtual class method used to deinitialise resources for the state.
            */
            virtual const bool deinit() = 0;

            /*!
            \brief Pure virtual class method used to start the state for the first time.
            */
            virtual const bool startup() = 0;

            /*!
            \brief Pure virtual class method used to free state resources. Should only be called on object destruction.
            */
            virtual const bool shutdown() = 0;

            /*!
            \brief Pure virtual class method used to render state objects.
            */
            virtual void render() = 0;

            /*!
            \brief Pure virtual class method used to update state objects.
            */
            virtual const bool update(const float dt) = 0;

		protected:
            void changeManagerState(const std::string& id);

			/*!
			\brief Pointer to frame instance.
			*/
		    Frame* m_frame;

			InputManager* m_input;
        private:
            void setStateManager(StateManager& state_manager);

            /*!
            \brief String used to identify the state.
            */
            std::string m_id;

            StateManager* m_state_manager;
    };
}

#endif