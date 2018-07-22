#include "AudioManager.h"

namespace minish
{
    bool AudioManager::addMusic(const std::string& name, const  std::string& filepath)
    {
        std::unordered_map<std::string, std::string>::iterator it = m_music.find(name);

        if (it == m_music.end())
        {
            m_music.insert(std::pair<std::string, std::string>(name, filepath));
            return true;
        }

        return false;
    }

    bool AudioManager::loadSound(const std::string& name, const std::string& filepath)
    {
        std::unordered_map<std::string, sf::SoundBuffer>::iterator it = m_buffers.find(name);
        
        if (it == m_buffers.end())
        {
            m_buffers.insert(std::pair<std::string, sf::SoundBuffer>(name, sf::SoundBuffer()));
            return m_buffers[name].loadFromFile(filepath);
        }

        return false;
    }

    void AudioManager::playMusic(const std::string& name)
    {
        std::unordered_map<std::string, std::string>::iterator it = m_music.find(name);
        
        if (it == m_music.end())
            return;

        if (!(m_music_player.getStatus() == sf::SoundSource::Status::Playing))
        {
            m_music_player.stop();
            m_music_player.openFromFile(m_music[name]);
            m_music_player.play();
        }
    }

    void AudioManager::playSound(const std::string& name)
    {
        std::unordered_map<std::string, sf::SoundBuffer>::iterator it = m_buffers.find(name);

        if (it == m_buffers.end())
            return;

        for (auto& sound_ : m_sound_player)
        {
            if (sound_.getStatus() == sf::SoundSource::Stopped)
            {
                sound_.setBuffer(m_buffers[name]);
                sound_.play();
                return;
            }
        }
    }

    void AudioManager::removeMusic(const std::string& name)
    {
        m_music.erase(name);
    }

    void AudioManager::removeSound(const std::string& name)
    {
        m_buffers.erase(name);
    }

    void AudioManager::setMusicLoop(bool loop)
    {
        m_music_player.setLoop(loop);
    }

    void AudioManager::setMusicVolume(float volume)
    {
        m_music_player.setVolume(volume);
    }

    void AudioManager::stopMusic()
    {
        m_music_player.stop();
    }
}