#ifndef MINISH_INPUTMANAGER_H
#define MINISH_INPUTMANAGER_H

#include <SFML/System/Vector2.hpp>

namespace sf
{
    class RenderWindow;
}

namespace minish
{
    /*!
    * \brief Class to handle raw input from SFML.
    * \author Jonathan Duncanson
    */
    class InputManager
    {
        public:
            /*!
            \brief Default constructor, takes pointer to sf::RenderWindow as argument.
            */
            InputManager(sf::RenderWindow* hwnd);

            /*!
            \brief Function to return the given controller axis' position.
            */
            float getControllerAxis(const int code);

            /*!
            \brief Function to return the mouse's position.
            */
            sf::Vector2i getMousePosition();

            /*!
            \brief Function to return the state of a controller button.
            */
            bool isControllerButtonPressed(const int code);

            /*!
            \brief Function to return the state of a key.
            */
            bool isKeyPressed(const int code);

            /*!
            \brief Function to return the state of a mouse button.
            */
            bool isMouseButtonPressed(const int code);

            /*!
            \brief Updates the class member variables with data from SFML.
            */
            void update();
        private:
            /*!
            \brief Sets every axis member variable to their respective current states.
            */
            void setControllerAxisStates();

            /*!
            \brief Sets a controller button member variable to a state.
            */
            void setControllerButtonState(const int code, const bool state);

            /*!
            \brief Sets a key member variable to a state.
            */
            void setKeyState(const int code, const bool state);

            /*!
            \brief Sets a mouse button member variable to a state.
            */
            void setMouseButtonState(const int code, const bool state);

            /*!
            \brief Sets the mouse button position variable to a position.
            */
            void setMousePosition(const sf::Vector2i position);

            /*!
            \brief Stores the key states.
            */
            bool m_keys[128]{false};

            /*!
            \brief Stores the mouse button states.
            */
            bool m_mouse_buttons[5]{false};

            /*!
            \brief Stores the mouse position.
            */
            sf::Vector2i m_mouse_position;

            /*!
            \brief Stores the controller button states.
            */
            bool m_controller_buttons[32]{false};

            /*!
            \brief Stores axis positions of the controller.
            */
            float m_controller_axis[8]{0.0f};

            /*!
            \brief Stores a pointer to the application window.
            */
            sf::RenderWindow* m_hwnd = nullptr;
    };
}

#endif