#include "Application.h"

#include <chrono>

namespace minish
{
    Application::Application(unsigned int thread_count, unsigned int window_width, unsigned int window_height, std::string app_title) 
    : 
    m_running(true), m_subsystemsync(0), m_threadsync(0)
    {
        m_threads.resize(thread_count - 1); //takes into account main execution thread
        m_wnd.create(sf::VideoMode(window_width, window_height), app_title, sf::Style::Close);
    }

    void Application::addThreadableSubsystem(Subsystem& subsystem)
    {
        for (auto& subsystem_ : m_subsystems)
        {
            if (subsystem_ == &subsystem)
            {
                return;
            }
        }
        m_subsystems.push_front(&subsystem);
    }

    void Application::removeThreadableSubsystem(Subsystem& subsystem)
    {
        std::forward_list<Subsystem*>::iterator it;
        while (it != m_subsystems.end())
        {
            if (*it == &subsystem)
            {
                m_subsystems.erase_after(it);
                return;
            }
        }
    }

    void Application::run()
    {
        startup();
        m_deltaTimer.restart();
        while(m_running)
        {
            toggleSubsystemFlags();
            m_running = update(m_deltaTimer.getElapsedTime().asSeconds());
            syncThreads();
            render();
            m_deltaTimer.restart();
        }
        shutdown();
    }

    void Application::syncSubsystems()
    {
        while(m_running)
        {
            if (m_subsystemsync < std::distance(m_subsystems.begin(), m_subsystems.end()))
            {
                Subsystem* subsystem = nullptr;
                m_subsystem_mutex.lock();
                subsystem = getNextSubsystem();
                subsystem->toggleUpdateFlag();
                m_subsystemsync++;
                m_subsystem_mutex.unlock();
                if (subsystem)
                    subsystem->update(m_deltaTimer.getElapsedTime().asSeconds());
            }
            else
            {
                syncThreads();
            }
        }
        
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

    Subsystem* Application::getNextSubsystem()
    {
        for (auto& subsystem_ : m_subsystems)
        {
            if (!subsystem_->getUpdateFlag())
            {
                return subsystem_;
            }
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

    void Application::toggleSubsystemFlags()
    {
        for (auto& subsystem_ : m_subsystems)
        {
            subsystem_->toggleUpdateFlag();
        }
    }
}