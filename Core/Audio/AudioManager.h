#ifndef MINISH_AUDIOMANAGER_H
#define MINISH_AUDIOMANAGER_H

#include <unordered_map>
#include <string>

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>


namespace minish
{
    /*!
    * \brief Class to handle playing sounds and music using SFML.
    * \author Jonathan Duncanson
    */
    class AudioManager
    {
        public:
            /*!
        	\brief Class method that adds the music filepath to the music map.
        	*/
            bool addMusic(std::string& name, std::string& filepath);

            /*!
        	\brief Class method that loads the sound into memory to the sounds map.
        	*/
            bool loadSound(std::string& name, std::string& filepath);

            /*!
        	\brief Class method that plays the given music track.
        	*/
            void playMusic(std::string& name);

            /*!
        	\brief Class method that plays the given sound.
        	*/
            void playSound(std::string& name);

            /*!
        	\brief Class method that removes the given music from the music map.
        	*/
            void removeMusic(std::string& name);

            /*!
        	\brief Class method that removes the given sound from the sounds map.
        	*/
            void removeSound(std::string& name);
        private:
            /*!
        	\brief Unordered map that stores SoundBuffers.
        	*/
            std::unordered_map<std::string, sf::SoundBuffer> m_buffers;

            /*!
        	\brief Unordered map that stores music filepaths.
        	*/
            std::unordered_map<std::string, std::string> m_music;

            /*!
        	\brief SFML object to play music. Maximum one music track at a time.
        	*/
            sf::Music m_music_player;

            /*!
        	\brief SFML objects to play sounds. Maximum 8 sound effects at a time.
        	*/
            sf::Sound m_sound_player[8];
    };
}

#endif