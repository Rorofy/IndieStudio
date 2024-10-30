/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SoundFX
*/

#ifndef SOUNDFX_HPP_
#define SOUNDFX_HPP_

#include "sfml/Music.hpp"
#include "sfml/Sound.hpp"

namespace indie
{
    class SoundFX {
        public:
            SoundFX() = default;
            ~SoundFX() {
                if (_music != nullptr) _music->stop();
                if (_sound != nullptr) _sound->stop();
            }

            void setSound(const std::string &path) {
                _sound = std::make_unique<sfml::SoundGame>(path);
            }

            void setMusic(const std::string &path) {
                _music = std::make_unique<sfml::MusicGame>(path);
                if (_music) {
                    _music->play();
                    _music->setLoop(true);
                }
            }

            [[nodiscard]] std::shared_ptr<sfml::SoundGame> getSound(void) const
            {
                return _sound;
            }

            [[nodiscard]] std::shared_ptr<sfml::MusicGame> getMusic(void) const
            {
                return _music;
            }

            void clear(void) {
                if (_music != nullptr) _music->stop();
                if (_sound != nullptr) _sound->stop();
            }

            SoundFX &operator=(SoundFX &operand) {
                if (_sound != nullptr) _sound->stop();
                if (_music != nullptr) _music->stop();
                _sound = operand.getSound();
                _music = operand.getMusic();
                return *this;
            }
        private:
            std::shared_ptr<sfml::SoundGame> _sound;
            std::shared_ptr<sfml::MusicGame> _music;
    };
    indie::Entity createSoundEntity(indie::Scene &scene, const std::string &path, long lifespan, bool looped = false);
    indie::Entity createSoundEntityCallback(indie::Scene &scene, const std::string &path, long lifespan,
        const std::function<void (indie::Scene &, indie::Entity)> &, bool looped = false);
}

#endif /* !SOUNDFX_HPP_ */