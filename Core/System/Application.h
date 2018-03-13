#ifndef MINISH_APPLICATION_H
#define MINISH_APPLICATION_H

#include <mutex>
#include <thread>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "StateManager.h"

namespace minish
{
    class Application
    {
        public:
            Application(unsigned int thread_count);
            virtual void render() = 0;
            void run();
            virtual void shutdown();
            virtual void startup();
            virtual void update(const float dt) = 0;
        protected:
            void syncThreads();
        private:
            std::mutex m_sync_mutex;
            std::vector<std::thread*> m_threads;
            sf::RenderWindow m_wnd;
            sf::Clock m_deltaTimer;
            StateManager m_state_manager;
            bool m_running = false;
            int m_threadsync = 0;

            
    };
}

#endif