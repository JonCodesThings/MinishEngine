#include "Application.h"

#include <chrono>

namespace minish
{
    Application::Application(unsigned int thread_count)
    {
        m_threads.resize(thread_count - 1);
    }

    void Application::run()
    {
        m_deltaTimer.restart();
        while(m_running)
        {
            update(m_deltaTimer.getElapsedTime().asSeconds());
            syncThreads();
            render();
            m_deltaTimer.restart();
        }
    }

    void Application::startup()
    {
        m_running = true;
    }

    void Application::shutdown()
    {
        m_running = false;
    }

    void Application::syncThreads() //basic thread barrier
    {
        if (m_threadsync < m_threads.size() + 1) //takes into account main execution thread
        {
            std::this_thread::yield();
            m_sync_mutex.lock();
            m_threadsync++;
            m_sync_mutex.unlock();
        }
    }

    void Application::post_render()
    {
        m_wnd.clear(sf::Color::Black);
    }

    void Application::pre_render()
    {
        m_wnd.display();
    }
}