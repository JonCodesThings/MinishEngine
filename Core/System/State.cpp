#include "State.h"

namespace minish
{
    State::State(sf::RenderWindow& hwnd, std::string& id) : m_hwnd(&hwnd), m_id(id)
    {}

    State::~State()
    {
    }

    std::string State::getID()
    {
        return m_id;
    }
}