#ifndef MINISH_ANIMATION_H
#define MINISH_ANIMATION_H

#include <SFML/Graphics/Rect.hpp>

namespace minish
{
    /*!
    * \brief Class to store sprite animation data.
    * \author Jonathan Duncanson
    */
    class Animation
    {
        public:
            /*!
        	\brief Default constructor.
        	*/
            Animation();

            /*!
        	\brief Constructor that initializes values for starting frame, frame size, total frames in the animation and the speed of the animation.
        	*/
            Animation(sf::Vector2i& frame_begin, sf::Vector2i& frame_size, const int total_frames, const float animation_speed);

            /*!
        	\brief Class method that pauses the animation at the current frame.
        	*/
            void pause();

            /*!
        	\brief Class method that plays the animation.
        	*/
            void play();

            /*!
        	\brief Class method that sets the speed of the animation.
        	*/
            void setAnimationSpeed(const float speed);

            /*!
        	\brief Class method that sets the position of the animation's starting frame.
        	*/
            void setAnimationStart(sf::Vector2i& frame_begin);

            /*!
        	\brief Class method that sets the size of the frame.
        	*/
            void setFrameSize(sf::Vector2i& frame_size);

            /*!
        	\brief Class method that sets the total number of frames.
        	*/
            void setTotalFrames(const int total_frames);

            /*!
        	\brief Class method that pauses the animation and puts it back to the first frame.
        	*/
            void stop();

            /*!
        	\brief Class method that updates the animation.
        	*/
            const sf::IntRect& update(const float dt);
        private:
            /*!
        	\brief Rect that stores the current frame.
        	*/
            sf::IntRect m_frame;

            /*!
        	\brief Stores the frame's position and size.
        	*/
            sf::Vector2i m_frame_begin, m_frame_size; 

            /*!
        	\brief Stores total frames and the current frame of animation.
        	*/
            int m_total_frames, m_current_frame;

            /*!
        	\brief Stores the current timer value and the speed of the animation.
        	*/
            float m_timer, m_animation_speed;

            /*!
        	\brief Stores whether or not the animation is playing.
        	*/
            bool m_playing;
    };
}

#endif