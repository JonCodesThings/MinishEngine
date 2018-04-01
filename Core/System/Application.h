#ifndef MINISH_APPLICATION_H
#define MINISH_APPLICATION_H

#include <forward_list>
#include <mutex>
#include <thread>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include <Core/Graphics/Frame.h>
#include "StateManager.h"
#include "Subsystem.h"

namespace minish
{
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
            Application(unsigned int thread_count, const sf::Vector2u& window_dimensions, const sf::Vector2u& target_dimensions, std::string app_title);

            /*!
        	\brief Class member that adds a threadable subsystem.
        	*/  
            void addThreadableSubsystem(Subsystem& subsystem);

            /*!
        	\brief Class member that removes a threadable subsystem.
        	*/  
            void removeThreadableSubsystem(Subsystem& subsystem);

            /*!
        	\brief Pure virtual class member for rendering.
        	*/ 
            virtual void render() = 0;

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
            virtual bool update(const float dt) = 0;
        protected:
            /*!
        	\brief Class member that runs update functions on threadable subsystems and makes sure all subsystems are updated.
        	*/ 
            void syncSubsystems();
            /*!
        	\brief Class member that makes sure all threads are synced. Also known as a barrier.
        	*/ 
            void syncThreads();

            /*!
        	\brief Application SFML window.
        	*/ 
            sf::RenderWindow m_wnd;

            /*!
        	\brief Application frame.
        	*/ 
            Frame m_frame;

			/*!
			\brief Gamestate manager.
			*/
			StateManager m_state_manager;

        private:
            /*!
        	\brief Returns the next subsystem that requires updating.
        	*/ 
            Subsystem* getNextSubsystem();

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
            void toggleSubsystemFlags();

            /*!
        	\brief Mutexes used to handle threading related issues.
        	*/
            std::mutex m_sync_mutex, m_subsystem_mutex;

            /*!
        	\brief Application threads.
        	*/
            std::vector<std::thread*> m_threads;

            /*!
        	\brief Singly linked list of subsystems.
        	*/
            std::forward_list<Subsystem*> m_subsystems;

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
            int m_threadsync, m_subsystemsync;

            /*!
        	\brief Variables used for multi-resolution support and to store deltatime.
        	*/
            float m_target_aspect_ratio, m_dt;
    };
}

#endif