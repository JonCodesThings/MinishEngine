#include "Application.h"

#include <chrono>

namespace minish
{
    Application::Application(unsigned int thread_count)
    {
        m_threads.resize(thread_count - 1);
    }

    void Application::syncThreads()
    {
        if (m_threadsync < m_threads.size() + 1) //takes into account main execution thread
        {
            std::this_thread::yield();
            m_sync_mutex.lock();
            m_threadsync++;
            m_sync_mutex.unlock();
        }
    }
}