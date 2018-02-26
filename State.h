#ifndef MINISH_STATE_H
#define MINISH_STATE_H

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
            State(sf::RenderWindow& hwnd, std::string& id);

            /*!
            \brief Default destructor, calls shutdown function to free resources.
            */
            ~State();

            /*!
            \brief Pure virtual function used to initialise resources for the state.
            */
            virtual bool init() = 0;

            /*!
            \brief Pure virtual function used to deinitialise resources for the state.
            */
            virtual bool deinit() = 0;

            /*!
            \brief Pure virtual function used to start the state for the first time.
            */
            virtual bool startup() = 0;

            /*!
            \brief Pure virtual function used to free state resources. Should only be called on object destruction.
            */
            virtual bool shutdown() = 0;

            /*!
            \brief Pure virtual function used to render state objects.
            */
            virtual void render() = 0;

            /*!
            \brief Pure virtual function used to update state objects.
            */
            virtual void update(const float dt) = 0;
        private:
            /*!
            \brief Pointer to SFML window instance.
            */
            sf::RenderWindow* m_hwnd;

            /*!
            \brief String used to identify the state.
            */
            std::string m_id;
    };
}

#endif