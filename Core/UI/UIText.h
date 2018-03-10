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
            /*!
            \brief Sets the text's font.
            */
            void setFont(sf::Font& font);

            /*!
            \brief Sets the text's string.
            */
            void setTextString(std::string& text_string);
        private:
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