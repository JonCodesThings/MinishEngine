#include "Animation.h"

namespace minish
{
    Animation::Animation() : 
    m_frame_size(0, 0, 0, 0), m_total_frames(0), m_current_frame(0), m_timer(0.0f), m_animation_speed(1.0f), m_playing(false)
    {}

    Animation::Animation(sf::IntRect& frame_size, const int total_frames, const float animation_speed):
    m_frame_size(frame_size), m_total_frames(total_frames), m_current_frame(0), m_timer(0.0f), m_animation_speed(animation_speed), m_playing(false)
    {}

    void Animation::pause()
    {
        m_playing = false;
    }

    void Animation::play()
    {
        m_playing = true;
    }

    void Animation::setAnimationSpeed(const float animation_speed)
    {
        m_animation_speed = animation_speed;
    }

    void Animation::setFrameSize(sf::IntRect& frame_size)
    {
        m_frame_size = frame_size;
    }

    void Animation::setTotalFrames(const int total_frames)
    {
        m_total_frames = total_frames;
    }

    void Animation::stop()
    {
        m_playing = false;
        m_current_frame = 0;
    }

    const sf::IntRect Animation::update(float dt)
    {
        if (m_playing)
        {
            m_timer += dt;
            if (m_timer >= m_animation_speed)
            {
                m_current_frame++;
                m_timer = 0.0f;
                if (m_current_frame > m_total_frames)
                {
                    m_current_frame = 0;
                }
            }
        }
        return sf::IntRect(m_frame_size.left + (m_frame_size.width * m_current_frame), m_frame_size.top, m_frame_size.width, m_frame_size.height);
    }
}