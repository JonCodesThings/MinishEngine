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
    /*!
    * \brief Abstact class for gamestate management.
    * \author Jonathan Duncanson
    */
    class State
    {
        public:
            /*!
            \brief Default constructor, passes in reference to window and string id for state switching purposes.
            */
            State(Frame& frame, std::string& id, InputManager& input);

            /*!
            \brief Default destructor, calls shutdown class method to free resources.
            */
            ~State();

            /*!
            \brief Returns the state's id.
            */
            std::string getID();

            /*!
            \brief Pure virtual class method used to initialise resources for the state.
            */
            virtual bool init() = 0;

            /*!
            \brief Pure virtual class method used to deinitialise resources for the state.
            */
            virtual bool deinit() = 0;

            /*!
            \brief Pure virtual class method used to start the state for the first time.
            */
            virtual bool startup() = 0;

            /*!
            \brief Pure virtual class method used to free state resources. Should only be called on object destruction.
            */
            virtual bool shutdown() = 0;

            /*!
            \brief Pure virtual class method used to render state objects.
            */
            virtual void render() = 0;

            /*!
            \brief Pure virtual class method used to update state objects.
            */
            virtual void update(const float dt) = 0;

		protected:

			/*!
			\brief Pointer to frame instance.
			*/
			Frame* m_frame;

			InputManager* m_input;
        private:

            /*!
            \brief String used to identify the state.
            */
            std::string m_id;
    };
}

#endif