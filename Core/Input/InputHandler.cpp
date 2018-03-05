#include "System/Action.h"
#include "InputHandler.h"
#include "InputManager.h"

namespace minish
{
    void InputHandler::bindActionToControllerAxis(Action& action, const int code)
    {
        unbindActionFromControllerAxis(code);
        m_controller_axis[code] = &action;
    }

    void InputHandler::bindActionToControllerButton(Action& action, const int code)
    {
        unbindActionFromControllerButton(code);
        m_controller_buttons[code] = &action;
    }

    void InputHandler::bindActionToKey(Action& action, const int code)
    {
        unbindActionFromKey(code);
        m_keys[code] = &action;
    }

    void InputHandler::bindActionToMouseButton(Action& action, const int code)
    {
        unbindActionFromMouseButton(code);
        m_mouse_buttons[code] = &action;
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

    void InputHandler::unbindActionFromControllerButton(const int code)
    {
        if (m_controller_buttons[code] != nullptr)
        {
            m_controller_buttons[code] = nullptr;
        }
    }

    void InputHandler::unbindActionFromKey(const int code)
    {
        if (m_keys[code] != nullptr)
        {
            m_keys[code] = nullptr;
        }
    }

    void InputHandler::unbindActionFromMouseButton(const int code)
    {
        if (m_mouse_buttons[code] != nullptr)
        {
            m_mouse_buttons[code] = nullptr;
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
                    m_controller_axis[axis]->onAction();
                    m_prev_controller_axis_vals[axis] = m_input_manager->getControllerAxis(axis);
                }
            }

            //calls actions based on controller buttons
            for (int button = 0; button < 32; button++)
            {
                if (m_input_manager->isControllerButtonPressed(button))
                {
                    m_controller_buttons[button]->onAction();
                }
            }

            //calls actions based on keyboard
            for (int key = 0; key < 128; key++)
            {
                if (m_input_manager->isKeyPressed(key))
                {
                    m_keys[key]->onAction();
                }
            }
        }
    }
}