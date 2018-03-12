#ifndef MINISH_APPLICATION_H
#define MINISH_APPLICATION_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "StateManager.h"

namespace minish
{
    class Application
    {
        public:
            Application();
            void run();
            virtual void shutdown() = 0;
            virtual void startup() = 0;
        private:
            sf::RenderWindow m_wnd;
            sf::Clock m_deltaTimer;
            StateManager m_state_manager;
            bool m_running = false;

            virtual void update(const float dt) = 0;
            virtual void render() = 0;
    };
}

#endif