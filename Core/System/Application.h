#ifndef MINISH_APPLICATION_H
#define MINISH_APPLICATION_H

#include <forward_list>
#include <mutex>
#include <thread>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include <Core/Audio/AudioManager.h>
#include <Core/Graphics/Frame.h>
#include <Core/Graphics/TextureManager.h>
#include <Core/Input/InputHandler.h>
#include <Core/Input/InputManager.h>

#include "StateManager.h"
#include "Task.h"

namespace minish
{
    struct ApplicationSystem
    {
        ApplicationSystem(sf::RenderWindow& wnd) : m_frame(wnd), m_input_manager(&wnd) {};
        ~ApplicationSystem() {};        
        /*
        \brief Audio manager.
        */
        AudioManager m_audio_manager;

        /*
        \brief Application frame.
        */
        Frame m_frame;

        /*
        \brief Input manager.
        */
        InputManager m_input_manager;

        /*
        \brief Rebindable input handler.
        */
        InputHandler m_input_handler;

        /*
        \brief Texture manager.
        */
        TextureManager m_texture_manager;

    };

	/*!
   * \brief Abstract class used to represent the game application itself.
   * \author Jonathan Duncanson
   */
	class Application
	{
	public:
		/*!
		\brief Default constructor. Sets the number of threads, window dimensions, target dimensions and window title.
		*/
		Application(const float target_frame_time, const sf::Vector2u& window_dimensions, const sf::Vector2u& target_dimensions, const std::string& app_title);

		ApplicationSystem& getApplicationSystem();

		/*!
		\brief Pure virtual class member for rendering.
		*/
		virtual void render(float update_difference) = 0;

		/*!
		\brief Class member that resizes the window and adjusts the position of the frame accordingly.
		*/
		void resizeWindow(const sf::Vector2u& window_dimensions);

		/*!
		\brief Class member that runs the core application loop.
		*/
		void run();

		/*!
		\brief Pure virtual class member that runs on application shutdown.
		*/
		virtual void shutdown() = 0;

		/*!
		\brief Pure virtual class member that runs on application startup.
		*/
		virtual void startup() = 0;

		/*!
		\brief Pure virtual class member that runs update functions on non-threadable subsystems and the state manager.
		*/
		virtual const bool update(const float dt) = 0;
	protected:

		ApplicationSystem m_application_system;

		/*!
		\brief Application SFML window.
		*/
		sf::RenderWindow m_wnd;

		/*!
		\brief Gamestate manager.
		*/
		StateManager m_state_manager;

	private:

		/*!
		\brief Class member that is called after render().
		*/
		void post_render();

		/*!
		\brief Class member that is called before render().
		*/
		void pre_render();

		/*!
		\brief Timer used to measure delta time.
		*/
		sf::Clock m_deltaTimer;

		/*!
		\brief Boolean that stores whether or not the application is running.
		*/
		bool m_running;

		/*!
		\brief Variables used for multi-resolution support and to store deltatime.
		*/
		float m_target_aspect_ratio, m_dt, m_target_dt;

		sf::Vector2u m_target_dimensions;
	};

#ifdef MINISH_EXPERIMENTAL
    /*!
    * \brief Abstract class used to represent the game application itself.
    * \author Jonathan Duncanson
    */
    class Application
    {
        public:
            /*!
        	\brief Default constructor. Sets the number of threads, window dimensions, target dimensions and window title.
        	*/  
            Application(unsigned int thread_count, const sf::Vector2u& window_dimensions, const sf::Vector2u& target_dimensions, const std::string& app_title);

            /*!
        	\brief Class member that adds a threadable subsystem.
        	*/  
            void addTask(Task& task);

            ApplicationSystem& getApplicationSystem();

            /*!
        	\brief Class member that removes a threadable subsystem.
        	*/  
            void removeTask(Task& task);

            /*!
        	\brief Pure virtual class member for rendering.
        	*/ 
            virtual void render() = 0;

            /*!
            \brief Class member that resizes the window and adjusts the position of the frame accordingly.
            */
            void resizeWindow(const sf::Vector2u& window_dimensions);

            /*!
        	\brief Class member that runs the core application loop.
        	*/ 
            void run();

            /*!
        	\brief Pure virtual class member that runs on application shutdown.
        	*/ 
            virtual void shutdown() = 0;

            /*!
        	\brief Pure virtual class member that runs on application startup.
        	*/ 
            virtual void startup() = 0;

            /*!
        	\brief Pure virtual class member that runs update functions on non-threadable subsystems and the state manager.
        	*/ 
            virtual const bool update(const float dt) = 0;
        protected:
            /*!
        	\brief Class member that runs update functions on threadable tasks and makes sure all tasks are updated.
        	*/ 
            void syncTasks();
            /*!
        	\brief Class member that makes sure all threads are synced. Also known as a barrier.
        	*/ 
            void syncThreads();

            ApplicationSystem m_application_system;

            /*!
        	\brief Application SFML window.
        	*/ 
            sf::RenderWindow m_wnd;

        	/*!
		    \brief Gamestate manager.
		    */
		    StateManager m_state_manager;

        private:
            /*!
        	\brief Returns the next subsystem that requires updating.
        	*/ 
            Task* getNextTask();

            /*!
        	\brief Class member that is called after render().
        	*/
            void post_render();

            /*!
        	\brief Class member that is called before render().
        	*/
            void pre_render();

            /*!
        	\brief Class member that toggles all subsystem update flags.
        	*/
            void toggleTaskFlags();

            /*!
        	\brief Mutexes used to handle threading related issues.
        	*/
            std::mutex m_sync_mutex, m_task_mutex;

            /*!
        	\brief Application threads.
        	*/
            std::vector<std::thread*> m_threads;

            /*!
        	\brief Singly linked list of tasks.
        	*/
            std::forward_list<Task*> m_tasks;

            /*!
        	\brief Timer used to measure delta time.
        	*/
            sf::Clock m_deltaTimer;

            /*!
        	\brief Boolean that stores whether or not the application is running.
        	*/
            bool m_running;

            /*!
        	\brief Variables used to sync threads and subsystems.
        	*/
            unsigned int m_threadsync, m_tasksync;

            /*!
        	\brief Variables used for multi-resolution support and to store deltatime.
        	*/
            float m_target_aspect_ratio, m_dt;

            sf::Vector2u m_target_dimensions;
    };
#endif
}

#endif