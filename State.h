#ifndef MINISH_STATE_H
#define MINISH_STATE_H

#include <string>

namespace sf
{
    class RenderWindow;
}

namespace minish
{
    class State
    {
        public:
            State(sf::RenderWindow& hwnd, std::string& id);
            ~State();
            virtual bool init() = 0;
            virtual bool deinit() = 0;
            virtual bool startup() = 0;
            virtual bool shutdown() = 0;
            virtual void render() = 0;
            virtual void update(const float dt) = 0;
        private:
            sf::RenderWindow* m_hwnd;
            std::string m_id;
    };
}

#endif