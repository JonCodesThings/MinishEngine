#ifndef MINISH_UITEXT_H
#define MINISH_UITEXT_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "UIElement.h"

namespace minish
{
    class UIText : public UIElement
    {
        public:
            void setFont(sf::Font& font);
            void setTextString(std::string& text_string);
        private:
            sf::Font m_font;
            sf::Text m_text;
    };
}

#endif