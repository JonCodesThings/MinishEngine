#ifndef MINISH_INPUTMANAGER_H
#define MINISH_INPUTMANAGER_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

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

			void appendTextInput(const sf::Event& ev);

			void clearTextInput();

			void disableTextInput();

			void enableTextInput();

			void setFocus(const bool focus);

            /*!
            \brief Class method to return the given controller axis' position.
            */
            const float getControllerAxis(const int code) const;

            /*!
            \brief Class method to return the mouse's position.
            */
            const sf::Vector2i& getMousePosition() const;

			const std::string& getTextInput() const;

            /*!
            \brief Class method to return the state of a controller button.
            */
            const bool isControllerButtonPressed(const int code) const;

			const bool isControllerButtonReleased(const int code) const;

            /*!
            \brief Class method to return the state of a key.
            */
            const bool isKeyPressed(const int code) const;

			/*!
			\brief Class method to return if a key has been released.
			*/
			const bool isKeyReleased(const int code) const;

            /*!
            \brief Class method to return the state of a mouse button.
            */
            const bool isMouseButtonPressed(const int code) const;

			/*!
			\brief Class method to return if a mouse button has been released.
			*/
			const bool isMouseButtonReleased(const int code) const;

			const bool isTextInputEnabled() const;

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
			\brief Stores the previous key states.
			*/
			bool m_prev_keys[128]{false};

            /*!
            \brief Stores the mouse button states.
            */
            bool m_mouse_buttons[5]{false};

			/*!
			\brief Stores the previous mouse button states.
			*/
			bool m_prev_mouse_buttons[5]{false};

            /*!
            \brief Stores the mouse position.
            */
            sf::Vector2i m_mouse_position;

            /*!
            \brief Stores the controller button states.
            */
            bool m_controller_buttons[32]{false};

			/*!
			\brief Stores the previous controller button states.
			*/
			bool m_prev_controller_buttons[32]{ false };

            /*!
            \brief Stores axis positions of the controller.
            */
            float m_controller_axis[8]{0.0f};

			bool m_text_input_flag, m_focus;

			std::string m_text_input;

            /*!
            \brief Stores a pointer to the application window.
            */
            sf::RenderWindow* m_hwnd = nullptr;
    };
}

#endif