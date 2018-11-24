#include "Application.h"

#include <chrono>
#include <iostream>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace minish
{
	Application::Application(const float target_frame_time, const sf::Vector2u& window_dimensions, const sf::Vector2u& target_dimensions, const std::string& app_title)
		:
		m_application_system(m_wnd), m_state_manager(*this), m_running(true),
		m_target_aspect_ratio(((float)target_dimensions.x / (float)target_dimensions.y)), m_target_dt(target_frame_time), m_target_dimensions(target_dimensions)
	{
		m_wnd.create(sf::VideoMode(window_dimensions.x, window_dimensions.y), app_title, sf::Style::Close);
		m_application_system.m_frame.init(target_dimensions, m_wnd);
		resizeWindow(window_dimensions);
	}

#ifdef MINISH_EXPERIMENTAL
    Application::Application(unsigned int thread_count, const sf::Vector2u& window_dimensions, const sf::Vector2u& target_dimensions, const std::string& app_title) 
    : 
    m_application_system(m_wnd), m_state_manager(*this), m_running(true), m_threadsync(0), m_tasksync(0), 
    m_target_aspect_ratio(((float)target_dimensions.x / (float)target_dimensions.y)), m_target_dimensions(target_dimensions)
    {
        m_threads.resize(thread_count - 1); //takes into account main execution thread
        m_wnd.create(sf::VideoMode(window_dimensions.x, window_dimensions.y), app_title, sf::Style::Close);
        m_application_system.m_frame.init(target_dimensions, m_wnd);
        resizeWindow(window_dimensions);
    }
#endif

    ApplicationSystem& Application::getApplicationSystem()
    {
        return m_application_system;
    }

    void Application::resizeWindow(const sf::Vector2u& window_dimensions)
    {
        m_wnd.setSize(window_dimensions);
        m_application_system.m_frame.setView(sf::View(m_application_system.m_frame.getView().getCenter(), sf::Vector2f(m_target_dimensions)));
        m_application_system.m_frame.setScale(1.0f, 1.0f);
        m_application_system.m_frame.setPosition(0, 0);
        sf::View window_view;
        window_view.setSize(sf::Vector2f(m_application_system.m_frame.getRenderTarget().getSize().x, m_application_system.m_frame.getRenderTarget().getSize().y));
        if (((float)window_dimensions.x / (float)window_dimensions.y) == m_target_aspect_ratio)
        {
            window_view.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
        }
        else
        {
            float actual_aspect = ((float)window_dimensions.x / (float)window_dimensions.y);
            if (actual_aspect > m_target_aspect_ratio)
            {
                if (m_target_aspect_ratio == 4.0f/3.0f)
                {
                    if (actual_aspect == 16.0f/9.0f)
                        window_view.setViewport(sf::FloatRect(0.125f, 0.0f, 0.75f, 1.0f));
                    else
                        window_view.setViewport(sf::FloatRect(0.1f, 0.0f, 0.8f, 1.0f));
                }
                else
                {
                    if (actual_aspect == 4.0f/3.0f)
                        window_view.setViewport(sf::FloatRect(0.1f, 0.0f, 0.8f, 1.0f));
                }
            }
            else
            {
               
            }
            
        }
        
        window_view.setCenter(sf::Vector2f(m_application_system.m_frame.getRenderTarget().getSize().x / 2, m_application_system.m_frame.getRenderTarget().getSize().y / 2));
        m_wnd.setView(window_view);
    }

    void Application::run()
    {
        startup();
        m_dt = m_deltaTimer.restart().asSeconds();
		float lag = 0.0f;
        while(m_running)
        {
			lag += m_dt;
			while (lag >= m_target_dt)
			{
				m_running = update(m_target_dt);
				lag -= m_target_dt;
			}
				
			pre_render();
            render(lag / m_target_dt);
			post_render();
            m_dt = m_deltaTimer.restart().asSeconds();

            sf::Event ev;
			while (m_wnd.pollEvent(ev))
			{
				switch (ev.type)
				{
				case sf::Event::Closed:
					m_wnd.close();
					m_running = false;
					break;
				case sf::Event::TextEntered:
					if (m_application_system.m_input_manager.isTextInputEnabled())
						m_application_system.m_input_manager.appendTextInput(ev);
					break;
				case sf::Event::LostFocus:
					m_application_system.m_input_manager.setFocus(false);
					break;
				case sf::Event::GainedFocus:
					m_application_system.m_input_manager.setFocus(true);
					break;
				default:
					break;
				}
			}
        }
        m_application_system.m_frame.deinit();
        shutdown();
    }

#ifdef MINISH_EXPERIMENTAL

	void Application::run()
	{
		startup();
		m_dt = m_deltaTimer.restart().asSeconds();
		while (m_running)
		{
			toggleTaskFlags();
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
		m_application_system.m_frame.deinit();
		shutdown();
	}

	void Application::addTask(Task& task)
	{
		for (auto& task_ : m_tasks)
		{
			if (task_ == &task)
			{
				return;
			}
		}
		m_tasks.push_front(&task);
	}

	void Application::removeTask(Task& task)
	{
		std::forward_list<Task*>::iterator it;
		while (it != m_tasks.end())
		{
			if (*it == &task)
			{
				m_tasks.erase_after(it);
				return;
			}
		}
	}

    void Application::syncTasks()
    {
        while(m_running)
        {
            if (m_tasksync < std::distance(m_tasks.begin(), m_tasks.end()))
            {
                Task* task = nullptr;
                m_task_mutex.lock();
                task = getNextTask();
                m_tasksync++;
                m_task_mutex.unlock();
                if (task)
                    task->update(m_dt);
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

    Task* Application::getNextTask()
    {
        for (auto& task_ : m_tasks)
        {
            if (task_->getTaskState() == TASK_STATE::NOT_UPDATED)
            {
                return task_;
            }
        }
        return nullptr;
    }

	void Application::toggleTaskFlags()
	{
		for (auto& task_ : m_tasks)
		{
			task_->resetTaskState();
		}
	}

#endif

    void Application::post_render()
    {
        m_application_system.m_frame.post_render();
        m_wnd.draw(m_application_system.m_frame);
		m_wnd.display();
    }

    void Application::pre_render()
    {   
		m_wnd.clear(sf::Color::Black);
        m_application_system.m_frame.pre_render();
    }
}