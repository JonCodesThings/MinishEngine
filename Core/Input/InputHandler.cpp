#include "Core/System/Action.h"
#include "InputHandler.h"
#include "InputManager.h"

#include <iostream>

namespace minish
{
    void InputHandler::bindActionToControllerAxis(Action& action, const int code)
    {
        unbindActionFromControllerAxis(code);
        m_controller_axis[code] = &action;
    }

    void InputHandler::bindActionToControllerButtonPressed(Action& action, const int code)
    {
        unbindActionFromControllerButtonPressed(code);
        m_controller_buttons_pressed[code] = &action;
    }

	void InputHandler::bindActionToControllerButtonReleased(Action& action, const int code)
	{
		unbindActionFromControllerButtonReleased(code);
		m_controller_buttons_released[code] = &action;
	}

    void InputHandler::bindActionToKeyPressed(Action& action, const int code)
    {
        unbindActionFromKeyPressed(code);
        m_keys_pressed[code] = &action;
    }

	void InputHandler::bindActionToKeyReleased(Action& action, const int code)
	{
		unbindActionFromKeyReleased(code);
		m_keys_released[code] = &action;
	}

    void InputHandler::bindActionToMouseButtonPressed(Action& action, const int code)
    {
        unbindActionFromMouseButtonPressed(code);
        m_mouse_buttons_pressed[code] = &action;
    }

	void InputHandler::bindActionToMouseButtonReleased(Action& action, const int code)
	{
		unbindActionFromMouseButtonReleased(code);
		m_mouse_buttons_released[code] = &action;
	}

    void InputHandler::setInputManager(InputManager* const input_manager)
    {
        m_input_manager = input_manager;
    }

    void InputHandler::unbindActionFromControllerAxis(const int code)
    {
        if (m_controller_axis[code] != nullptr)
        {
            m_controller_axis[code] = nullptr;
        }
    }

    void InputHandler::unbindActionFromControllerButtonPressed(const int code)
    {
        if (m_controller_buttons_pressed[code] != nullptr)
        {
			m_controller_buttons_pressed[code] = nullptr;
        }
    }

	void InputHandler::unbindActionFromControllerButtonReleased(const int code)
	{
		if (m_controller_buttons_released[code] != nullptr)
		{
			m_controller_buttons_released[code] = nullptr;
		}
	}

    void InputHandler::unbindActionFromKeyPressed(const int code)
    {
        if (m_keys_pressed[code] != nullptr)
        {
			m_keys_pressed[code] = nullptr;
        }
    }

	void InputHandler::unbindActionFromKeyReleased(const int code)
	{
		if (m_keys_released[code] != nullptr)
		{
			m_keys_released[code] = nullptr;
		}
	}

    void InputHandler::unbindActionFromMouseButtonPressed(const int code)
    {
        if (m_mouse_buttons_pressed[code] != nullptr)
        {
			m_mouse_buttons_pressed[code] = nullptr;
        }
    }

	void InputHandler::unbindActionFromMouseButtonReleased(const int code)
	{
		if (m_mouse_buttons_released[code] != nullptr)
		{
			m_mouse_buttons_released[code] = nullptr;
		}
	}

    void InputHandler::update()
    {
        //checks if there a non nullptr value in m_input_manager
        if (m_input_manager)
        {
            //updates the input manager
            m_input_manager->update();

            //checks axis values, calls actions and stores changed values
            for (int axis = 0; axis < 8; axis++)
            {
                if (m_prev_controller_axis_vals[axis] != m_input_manager->getControllerAxis(axis))
                {
					if (m_controller_axis[axis])
						m_controller_axis[axis]->onAction();

                    m_prev_controller_axis_vals[axis] = m_input_manager->getControllerAxis(axis);
                }
            }

            //calls actions based on controller buttons
            for (int button = 0; button < 32; button++)
            {
                if (m_input_manager->isControllerButtonPressed(button))
                {
					if (m_controller_buttons_pressed[button])
						m_controller_buttons_pressed[button]->onAction();
                }
				if (m_input_manager->isControllerButtonReleased(button))
				{
					if (m_controller_buttons_released[button])
						m_controller_buttons_released[button]->onAction();
				}
            }

            //calls actions based on keyboard
            for (int key = 0; key < 128; key++)
            {
                if (m_input_manager->isKeyPressed(key))
                {
					if (m_keys_pressed[key])
						m_keys_pressed[key]->onAction();
                }

				if (m_input_manager->isKeyReleased(key))
				{
					if (m_keys_released[key])
						m_keys_released[key]->onAction();
				}
            }
        }
    }
}