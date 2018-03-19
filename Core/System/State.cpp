#include "State.h"

namespace minish
{
    State::State(sf::RenderWindow& hwnd, std::string& id, InputManager& input) : m_hwnd(&hwnd), m_id(id), m_input(&input)
    {}

    State::~State()
    {
    }

    std::string State::getID()
    {
        return m_id;
    }
}