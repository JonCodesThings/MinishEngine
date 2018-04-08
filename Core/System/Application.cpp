#include "Application.h"

#include <chrono>
#include <iostream>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace minish
{
    Application::Application(unsigned int thread_count, const sf::Vector2u& window_dimensions, const sf::Vector2u& target_dimensions, std::string app_title) 
    : 
    m_running(true), m_subsystemsync(0), m_threadsync(0), m_target_aspect_ratio(((float)target_dimensions.x / (float)target_dimensions.y))
    {
        m_threads.resize(thread_count - 1); //takes into account main execution thread
        m_wnd.create(sf::VideoMode(window_dimensions.x, window_dimensions.y), app_title, sf::Style::Close);
        m_frame.init(target_dimensions, m_wnd);
        if (window_dimensions == target_dimensions)
        {
            m_frame.setPosition(0, 0);
        }
        else if (((float)window_dimensions.x / (float)window_dimensions.y) == m_target_aspect_ratio)
        {
            m_frame.setPosition(0, 0);
            m_frame.setScale(((float)window_dimensions.x / (float)target_dimensions.x), ((float)window_dimensions.y / (float)target_dimensions.y));
        }
        else
        {
            float actual_aspect = ((float)window_dimensions.x / (float)window_dimensions.y);
            if (actual_aspect > m_target_aspect_ratio)
            {
                if (actual_aspect < 1.59f)
                {
                    float x_pos = ((float)window_dimensions.x - ((float)window_dimensions.y * (float)4/3)) / 2;
                    m_frame.setPosition(x_pos, 0);
                }
                else
                {
                    float y_pos = ((float)window_dimensions.y - ((float)window_dimensions.x * m_target_aspect_ratio)) /2;
                    m_frame.setPosition(0, y_pos);
                }
            }
            else
            {
               //TODO
            }
        }
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
            m_running = update(m_dt);
            syncThreads();
			pre_render();
            render();
			post_render();
            m_dt = m_deltaTimer.restart().asSeconds();

            sf::Event ev;
            if (m_wnd.pollEvent(ev) && ev.type == sf::Event::Closed)
            {
                m_wnd.close();
                m_running = false;
            }
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
                m_subsystemsync++;
                m_subsystem_mutex.unlock();
                if (subsystem)
                    subsystem->update(m_dt);
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
            m_sync_mutex.lock();
            m_threadsync++;
            m_sync_mutex.unlock();
        }
        do
        {
            std::this_thread::yield();
        } while (m_threadsync < m_threads.size() + 1);
    }

    Subsystem* Application::getNextSubsystem()
    {
        for (auto& subsystem_ : m_subsystems)
        {
            if (subsystem_->getSubsystemState() == SUBSYSTEM_STATE::NOT_UPDATED)
            {
                return subsystem_;
            }
        }
    }

    void Application::post_render()
    {
        m_frame.post_render();
        m_wnd.draw(m_frame);
		m_wnd.display();
    }

    void Application::pre_render()
    {   
		m_wnd.clear(sf::Color::Black);
        m_frame.pre_render();
    }

    void Application::toggleSubsystemFlags()
    {
        for (auto& subsystem_ : m_subsystems)
        {
            subsystem_->resetSubsystemState();
        }
    }
}