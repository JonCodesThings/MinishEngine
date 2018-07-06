#include "Animation.h"  

namespace minish
{
    Animation::Animation() : 
    m_frame_begin(0, 0), m_frame_size(0, 0), m_total_frames(0), m_current_frame(0), m_timer(0.0f), m_animation_speed(1.0f), m_playing(false)
    {}

    Animation::Animation(const sf::Vector2i& frame_begin, const sf::Vector2i& frame_size, const int total_frames, const float animation_speed):
    m_frame_begin(frame_begin), m_frame_size(frame_size), m_total_frames(total_frames), m_current_frame(0), 
    m_timer(0.0f), m_animation_speed(animation_speed), m_playing(false)
    {}

    const float Animation::getAnimationSpeed() const
    {
        return m_animation_speed;
    }

    const sf::Vector2i& Animation::getAnimationStart() const
    {
        return m_frame_begin;
    }

    const sf::IntRect& Animation::getCurrentFrame() const
    {
        return m_frame;
    }

    const int Animation::getFrameCount() const
    {
        return m_total_frames;
    }

    const sf::Vector2i& Animation::getFrameSize() const
    {
        return m_frame_size;
    }

    const bool Animation::getPlaying() const
    {
        return m_playing;
    }

    void Animation::pause()
    {
        m_playing = false;
    }

    void Animation::play()
    {
        m_frame.left = m_frame_begin.x;
        m_frame.top = m_frame_begin.y;
        m_frame.width = m_frame_size.x;
        m_frame.height = m_frame_size.y;
        m_playing = true;
    }

    void Animation::setAnimationSpeed(const float animation_speed)
    {
        m_animation_speed = animation_speed;
    }

    void Animation::setAnimationStart(const sf::Vector2i& frame_begin)
    {
        m_frame_begin = frame_begin;
        m_frame.top = m_frame_begin.y;
    }

    void Animation::setFrameSize(const sf::Vector2i& frame_size)
    {
        m_frame_size = frame_size;
        m_frame.width = m_frame_size.x;
        m_frame.height = m_frame_size.y;
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

    const sf::IntRect& Animation::update(float dt)
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
        m_frame.left = m_frame_begin.x + (m_frame_size.x * m_current_frame);
        return m_frame;
    }
}