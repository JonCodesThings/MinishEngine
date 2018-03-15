#ifndef MINISH_APPLICATION_H
#define MINISH_APPLICATION_H

#include <forward_list>
#include <mutex>
#include <thread>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

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
        	\brief Default constructor. Sets the number of threads, window dimensions and window title.
        	*/  
            Application(unsigned int thread_count, unsigned int window_width, unsigned int window_height, std::string app_title);

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

            virtual bool update(const float dt) = 0;
        protected:
            void syncSubsystems();
            void syncThreads();
            sf::RenderWindow m_wnd;
        private:
            void post_render();
            void pre_render();
            std::mutex m_sync_mutex;
            std::vector<std::thread*> m_threads;
            std::forward_list<Subsystem*> m_subsystems;
            sf::Clock m_deltaTimer;
            StateManager m_state_manager;
            bool m_running;
            int m_threadsync;
            int m_subsystemsync;
            
    };
}

#endif