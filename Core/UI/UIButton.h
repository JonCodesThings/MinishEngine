#ifndef MINISH_UIBUTTON_H
#define MINISH_UIBUTTON_H

#include "Core/Physics/AABB.h"
#include "UIElement.h"

namespace minish
{
    class Action;

    /*!
    * \brief Class used for UI buttons.
    * \author Jonathan Duncanson
    */
    class UIButton : public UIElement
    {
        public:
			UIButton();
            /*!
            \brief Returns the button's AABB.
            */
            const AABB& getAABB();

            /*!
            \brief Binds an action to the button.
            */
            void bindAction(Action& action);

            /*!
            \brief Calls the bound action's onAction() class method.
            */
            void onAction();

            /*!
            \brief Sets the color of the button.
            */
           void setColor(const sf::Color& color);

			void setSize(const sf::Vector2u& size);

            /*!
            \brief Binds the action from the button.
            */
            void unbindAction();
        private:
            /*!
            \brief Stores the AABB of the button.
            */
            AABB m_AABB;

            /*!
            \brief Stores the action bound to the button.
            */
            Action* m_action = nullptr;
    };
}

#endif