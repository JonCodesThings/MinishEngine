#include "UIText.h"

namespace minish
{
    void UIText::setFont(sf::Font& font)
    {
        m_font = font;
    }

    void UIText::setTextString(std::string& text_string)
    {
        m_text.setString(text_string);
    }
}