#include "AudioComponent.h"

namespace minish
{
    AudioComponent::AudioComponent() : m_audio_manager(nullptr) {}

    void AudioComponent::playMusic(const std::string& id)
    {
        if (m_audio_manager)
            m_audio_manager->playMusic(id);
    }

    void AudioComponent::playSound(const std::string& id)
    {
        if (m_audio_manager)
            m_audio_manager->playSound(id);
    }

    void AudioComponent::setAudioManager(AudioManager& audio_manager)
    {
        m_audio_manager = &audio_manager;
    }
}