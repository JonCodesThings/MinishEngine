#ifndef MINISH_AUDIOCOMPONENT_H
#define MINISH_AUDIOCOMPONENT_H

#include "AudioManager.h"
#include <Core/Entity/Component.h>

namespace minish
{
    class AudioComponent : public Component
    {
    public:
        /*!
        \brief Default constructor.
        */
        AudioComponent();

        /*!
        \brief Virtual destructor.
        */
        virtual ~AudioComponent() {};

        /*!
        \brief Class member that plays music on the current audio manager if available.
        */
        void playMusic(const std::string& id);

        /*!
        \brief Class member that plays a sound on the current audio manager if available.
        */
        void playSound(const std::string& id);

        /*!
        \brief Class member that sets the current audio manager.
        */
        void setAudioManager(AudioManager& audio_manager);
    private:
        AudioManager* m_audio_manager;
    };
}

#endif