#ifndef MINISH_SUBSYSTEM_H
#define MINISH_SUBSYSTEM_H

namespace minish
{
    /*!
    * \brief Abstract class used for gameplay subsystems.
    * \author Jonathan Duncanson
    */
    class Subsystem
    {
        public:
            /*!
        	\brief Virtual destructor.
        	*/
            virtual ~Subsystem();

            /*!
        	\brief Class member that returns the status of the update flag.
        	*/
            bool getUpdateFlag();

            /*!
        	\brief Class member that toggles the update flag. Called as each subsystem is updated and once all subsystems are updated.
        	*/
            void toggleUpdateFlag();

            /*!
        	\brief Pure virtual class member for updating the subsystem.
        	*/
            virtual void update(const float dt) = 0;
        protected:
            /*!
        	\brief Update flag that stores whether or not the subsystem has bee updated.
        	*/
            bool m_updated = false;
    };
}

#endif