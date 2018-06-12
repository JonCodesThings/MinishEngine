#ifndef MINISH_ACTION_H
#define MINISH_ACTION_H

namespace minish
{
    class InputManager;
    /*!
    * \brief Abstact class to handle actions. For more details see: http://gameprogrammingpatterns.com/command.html
    * \author Jonathan Duncanson
    */    
    class Action
    {
        public:
            /*!
            \brief Virtual destructor for abstract class.
            */
			virtual ~Action() {};

            /*!
            \brief Pure virtual function called when something happens.
            */
            virtual void onAction() = 0;
    };
}

#endif