#ifndef MINISH_AUDIOMANAGER_H
#define MINISH_AUDIOMANAGER_H

#include <unordered_map>
#include <string>

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>


namespace minish
{
    class AudioManager
    {
        public:
            bool addMusic(std::string& name, std::string& filepath);
            bool loadSound(std::string& name, std::string& filepath);
            void playMusic(std::string& name);
            void playSound(std::string& name);
            void removeMusic(std::string& name);
            void removeSound(std::string& name);
        private:
            std::unordered_map<std::string, sf::SoundBuffer> m_buffers;
            std::unordered_map<std::string, std::string> m_music;
            sf::Music m_music_player;
            sf::Sound m_sound_player[8];
    };
}

#endif