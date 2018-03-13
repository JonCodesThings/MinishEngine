#include "Application.h"

#include <chrono>

namespace minish
{
    void Application::syncThreads()
    {
        if (m_threadsync < m_threads.size())
        {
            std::this_thread::yield();
            m_sync_mutex.lock();
            m_threadsync++;
            m_sync_mutex.unlock();
        }
    }
}