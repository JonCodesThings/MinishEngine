#ifndef MINISH_ANIMATION_H
#define MINISH_ANIMATION_H

#include <SFML/Graphics/Rect.hpp>

namespace minish
{
    class Animation
    {
        public:
            Animation();
            Animation(sf::IntRect& frame_size, const int total_frames, const float animation_speed);
            void pause();
            void play();
            void setAnimationSpeed(const float speed);
            void setFrameSize(sf::IntRect& frame_size);
            void setTotalFrames(const int total_frames);
            void stop();
            const sf::IntRect& update(const float dt);
        private:
            sf::IntRect m_frame_size;
            int m_total_frames, m_current_frame;
            float m_timer, m_animation_speed;
            bool m_playing;
    };
}

#endif