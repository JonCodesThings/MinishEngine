#ifndef MINISH_INPUTHANDLER_H
#define MINISH_INPUTHANDLER_H

namespace minish
{
    class Action;
    class InputManager;

    /*!
    * \brief Class that implements rebindable controls.
    * \author Jonathan Duncanson
    */
    class InputHandler
    {
        public:
            /*
            \brief Function that binds an action to a controller axis.
            */
            void bindActionToControllerAxis(Action& action, const int code);

            /*
            \brief Function that binds an action to a controller button.
            */
            void bindActionToControllerButton(Action& action, const int code);

            /*
            \brief Function that binds an action to a key.
            */
            void bindActionToKey(Action& action, const int code);

            /*
            \brief Function that binds an action to a mouse button.
            */
            void bindActionToMouseButton(Action& action, const int code);

            /*
            \brief Function that sets the input manager to receive input from.
            */
            void setInputManager(InputManager* const input_manager);

            /*
            \brief Function that unbinds an action from a controller axis.
            */
            void unbindActionFromControllerAxis(const int code);

            /*
            \brief Function that unbinds an action from a controller button.
            */
            void unbindActionFromControllerButton(const int code);

            /*
            \brief Function that unbinds an action from a key.
            */
            void unbindActionFromKey(const int code);

            /*
            \brief Function that unbinds an action from a mouse button.
            */
            void unbindActionFromMouseButton(const int code);

            /*
            \brief Updates and calls bound actions based on input from the current input manager.
            */
            void update();
        private:

            /*
            \brief Stores a pointer to the current input manager.
            */
            InputManager* m_input_manager = nullptr;

            /*
            \brief Stores pointers to all actions bound to the keyboard.
            */
            Action* m_keys[128]{nullptr};

            /*
            \brief Stores pointers to all actions bound to the mouse buttons.
            */
            Action* m_mouse_buttons[5]{nullptr};

            /*
            \brief Stores pointers to all actions bound to the controller buttons.
            */
            Action* m_controller_buttons[32]{nullptr};

            /*
            \brief Stores pointers to all actions bound to the controller axes.
            */
            Action* m_controller_axis[8]{nullptr};

            /*
            \brief Stores previous controller axis values.
            */
            float m_prev_controller_axis_vals[8]{0.0f};
    };
}

#endif