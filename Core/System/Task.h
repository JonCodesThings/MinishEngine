#ifndef MINISH_SUBSYSTEM_H
#define MINISH_SUBSYSTEM_H

#include <unordered_set>

namespace minish
{

    enum class TASK_STATE
    {
        NOT_UPDATED,
        UPDATING,
        UPDATED,
        COMPLETED,
        ABORTED,
        FAILED
    };

    /*!
    * \brief Abstract class used for task based parallelism.
    * \author Jonathan Duncanson
    */
    class Task
    {
        public:
            /*!
        	\brief Virtual destructor.
        	*/
            virtual ~Task() {};

            /*!
        	\brief Class member that returns the status of the task.
        	*/
            TASK_STATE getTaskState();

            /*!
        	\brief Class member that resets the task state back to NOT_UPDATED.
        	*/
            void resetTaskState();

            /*!
        	\brief Function called to update the task, provided all the dependencies are updated. If not, the thread is put to sleep.
        	*/
            void update(const float dt);
        protected:

            /*!
        	\brief Pure virtual class member for updating the task.
        	*/
            virtual void updateTask(const float dt) = 0;

            /*!
        	\brief Stores the state of the task.
        	*/
           TASK_STATE m_state = TASK_STATE::NOT_UPDATED;

            /*!
        	\brief A list of the task's children.
        	*/
            std::unordered_set<Task*> m_children;
    };
}

#endif