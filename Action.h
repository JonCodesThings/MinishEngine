#ifndef MINISH_ACTION_H
#define MINISH_ACTION_H

namespace minish
{
    /*!
    * \brief Abstact class to handle actions. For more details see: http://gameprogrammingpatterns.com/command.html
    * \author Jonathan Duncanson
    */
    class Action
    {
        public:
            virtual void onAction() = 0;
    };
}

#endif