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
            /*!
            \brief Class method that binds an action to a controller axis.
            */
            void bindActionToControllerAxis(Action& action, const int code);

            /*!
            \brief Class method that binds an action to a controller button when pressed.
            */
            void bindActionToControllerButtonPressed(Action& action, const int code);

			/*!
			\brief Class method that binds an action to a controller button when released.
			*/
			void bindActionToControllerButtonReleased(Action& action, const int code);

            /*!
            \brief Class method that binds an action to a key when pressed.
            */
            void bindActionToKeyPressed(Action& action, const int code);

			/*!
			\brief Class method that binds an action to a key when released.
			*/
			void bindActionToKeyReleased(Action& action, const int code);

            /*!
            \brief Class method that binds an action to a mouse button when pressed.
            */
            void bindActionToMouseButtonPressed(Action& action, const int code);

			/*!
			\brief Class method that binds an action to a mouse button when released.
			*/
			void bindActionToMouseButtonReleased(Action& action, const int code);

            /*!
            \brief Class method that sets the input manager to receive input from.
            */
            void setInputManager(InputManager* const input_manager);

            /*!
            \brief Class method that unbinds an action from a controller axis.
            */
            void unbindActionFromControllerAxis(const int code);

            /*!
            \brief Class method that unbinds an action from a controller button.
            */
            void unbindActionFromControllerButtonPressed(const int code);

			/*!
			\brief Class method that unbinds an action from a controller button.
			*/
			void unbindActionFromControllerButtonReleased(const int code);

            /*!
            \brief Class method that unbinds an action from a key.
            */
            void unbindActionFromKeyPressed(const int code);

			/*!
			\brief Class method that unbinds an action from a key.
			*/
			void unbindActionFromKeyReleased(const int code);

            /*!
            \brief Class method that unbinds an action from a mouse button.
            */
            void unbindActionFromMouseButtonPressed(const int code);

			/*!
			\brief Class method that unbinds an action from a mouse button.
			*/
			void unbindActionFromMouseButtonReleased(const int code);

            /*!
            \brief Updates and calls bound actions based on input from the current input manager.
            */
            void update();
        private:

            /*!
            \brief Stores a pointer to the current input manager.
            */
            InputManager* m_input_manager = nullptr;

            /*!
            \brief Stores pointers to all actions bound to the keyboard on key pressed.
            */
            Action* m_keys_pressed[128]{nullptr};

			/*!
			\brief Stores pointers to all actions bound to the keyboard on key released.
			*/
			Action* m_keys_released[128]{ nullptr };

            /*!
            \brief Stores pointers to all actions bound to the mouse buttons when pressed.
            */
            Action* m_mouse_buttons_pressed[5]{nullptr};

			/*!
			\brief Stores pointers to all actions bound to the mouse buttons when released.
			*/
			Action* m_mouse_buttons_released[5]{ nullptr };

            /*!
            \brief Stores pointers to all actions bound to the controller buttons when pressed.
            */
            Action* m_controller_buttons_pressed[32]{nullptr};

			/*!
			\brief Stores pointers to all actions bound to the controller buttons when released.
			*/
			Action* m_controller_buttons_released[32]{ nullptr };

            /*!
            \brief Stores pointers to all actions bound to the controller axes.
            */
            Action* m_controller_axis[8]{nullptr};

            /*!
            \brief Stores previous controller axis values.
            */
            float m_prev_controller_axis_vals[8]{0.0f};
    };
}

#endif