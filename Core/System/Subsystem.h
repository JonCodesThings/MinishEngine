#ifndef MINISH_SUBSYSTEM_H
#define MINISH_SUBSYSTEM_H

namespace minish
{
    class Subsystem
    {
        public:
            virtual ~Subsystem();
            virtual void update(const float dt) = 0;
    };
}

#endif