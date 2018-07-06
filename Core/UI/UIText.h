#ifndef MINISH_UITEXT_H
#define MINISH_UITEXT_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "UIElement.h"

namespace minish
{
    /*!
    * \brief Class used for UI text.
    * \author Jonathan Duncanson
    */
    class UIText : public UIElement
    {
        public:

			void render(sf::RenderTarget& target, sf::RenderStates states=sf::RenderStates::Default);

            /*!
            \brief Sets the text's font.
            */
            void setFont(const sf::Font& font);

			void setPosition(const sf::Vector2f& position);

			/*!
			\brief Sets the text's font size in pixels.
			*/
			void setTextSize(unsigned int size);

            /*!
            \brief Sets the text's string.
            */
            void setTextString(const std::string& text_string);
        private:
			/*!
			\brief SFML draw function.
			*/
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            /*!
            \brief Stores the text's font.
            */
            sf::Font m_font;

            /*!
            \brief An instance of the SFML text class.
            */
            sf::Text m_text;
    };
}

#endif