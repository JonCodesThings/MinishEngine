#include "InputManager.h"
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace minish
{
    InputManager::InputManager(sf::RenderWindow* hwnd) : m_hwnd(hwnd)
    {}


    float InputManager::getControllerAxis(const int code)
    {
        return m_controller_axis[code];
    }

    sf::Vector2i InputManager::getMousePosition()
    {
        return m_mouse_position;
    }

    bool InputManager::isControllerButtonPressed(const int code)
    {
        return m_controller_buttons[code];
    }

	bool InputManager::isControllerButtonReleased(const int code)
	{
		return !m_controller_buttons[code] && m_prev_controller_buttons[code];
	}

    bool InputManager::isKeyPressed(const int code)
    {
        return m_keys[code];
    }

	bool InputManager::isKeyReleased(const int code)
	{
		return !m_keys[code] && m_prev_keys[code];
	}

    bool InputManager::isMouseButtonPressed(const int code)
    {
        return m_mouse_buttons[code];
    }

	bool InputManager::isMouseButtonReleased(const int code)
	{
		return !m_mouse_buttons[code] && m_prev_mouse_buttons[code];
	}

    void InputManager::update()
    {
        //updates the joystick states
        sf::Joystick::update();

        //checks if the primary joystick is connected
        if (sf::Joystick::isConnected(0))
        {
            //updates the controller axis states
            setControllerAxisStates();

            //checks for any changes in button states and updates the button states as needed
            for (int button = 0; button < sf::Joystick::getButtonCount(0); button++)
            {
				m_prev_controller_buttons[button] = m_controller_buttons[button];

                if (sf::Joystick::isButtonPressed(0, button) != m_controller_buttons[button])
				{	
                    m_controller_buttons[button] = sf::Joystick::isButtonPressed(0, button);
                }
            }
        }

        //checks the key states and updates them as needed
        for (int key = 0; key < 128; key++)
        {
			m_prev_keys[key] = m_keys[key];

            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key)) != m_keys[key])
            {
                setKeyState(key, sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key)));
            }
        }

        //checks there is a handle to the window and updates the mouse position as needed
        if (m_hwnd != nullptr)
        {
            if (sf::Mouse::getPosition(*m_hwnd) != m_mouse_position)
            {
                m_mouse_position = sf::Mouse::getPosition(*m_hwnd);
            }
        }

        //updates the mouse button states as needed
        for (int mouse_button = 0; mouse_button < 5; mouse_button++)
        {
			m_prev_mouse_buttons[mouse_button] = m_mouse_buttons[mouse_button];

            if (sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(mouse_button)) != m_mouse_buttons[mouse_button])
            {
                m_mouse_buttons[mouse_button] = sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(mouse_button));
            }
        }

        
    }


    void InputManager::setControllerAxisStates()
    {
        //updates all controller axes as needed
        for (int axis = 0; axis < 8; axis++)
        {
            if (sf::Joystick::hasAxis(0, static_cast<sf::Joystick::Axis>(axis)))
            {
                m_controller_axis[axis] = sf::Joystick::getAxisPosition(0, static_cast<sf::Joystick::Axis>(axis));
            }
        }
    }

    void InputManager::setControllerButtonState(const int code, const bool state)
    {
        m_controller_buttons[code] = state;
    }

    void InputManager::setKeyState(const int code, const bool state)
    {
        m_keys[code] = state;
    }

    void InputManager::setMouseButtonState(const int code, const bool state)
    {
        m_mouse_buttons[code] = state;
    }

    void InputManager::setMousePosition(const sf::Vector2i position)
    {
        m_mouse_position = position;
    }
}