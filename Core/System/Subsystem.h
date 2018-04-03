#ifndef MINISH_SUBSYSTEM_H
#define MINISH_SUBSYSTEM_H

#include <unordered_set>

namespace minish
{

    enum class SUBSYSTEM_STATE
    {
        NOT_UPDATED,
        UPDATING,
        UPDATED
    };

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

            void addDependency(Subsystem& dependency);

            /*!
        	\brief Class member that returns the status of the subsystem.
        	*/
            SUBSYSTEM_STATE getSubsystemState();

            void removeDependency(Subsystem& dependency);

            /*!
        	\brief Class member that resets the subsystem state back to NOT_UPDATED.
        	*/
            void resetSubsystemState();

            /*!
        	\brief Function called to update the subsystem, provided all the dependencies are updated. If not, the thread is put to sleep.
        	*/
            void update(const float dt);
        protected:

            /*!
        	\brief Pure virtual class member for updating the subsystem.
        	*/
            virtual void updateSubsystem(const float dt) = 0;

            /*!
        	\brief Stores the state of the subsystem.
        	*/
            SUBSYSTEM_STATE m_state = SUBSYSTEM_STATE::NOT_UPDATED;

            /*!
        	\brief A list of the subsystem's dependencies.
        	*/
            std::unordered_set<Subsystem*> m_dependencies;
    };
}

#endif