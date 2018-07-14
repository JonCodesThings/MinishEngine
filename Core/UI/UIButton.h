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
            \brief Bind's an action to the button.
            */
            void bindAction(Action& action);

            /*!
            \brief Call's the bound action's onAction() class method.
            */
            void onAction();

            /*!
            \brief Set's the color of the button.
            */
           void setColor(const sf::Color& color);

			void setSize(const sf::Vector2u& size);

            /*!
            \brief Bind's the action from the button.
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