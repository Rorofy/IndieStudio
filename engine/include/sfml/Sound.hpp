/*
** EPITECH PROJECT, 2021
** yes
** File description:
** yes
*/

#ifndef SOUND_WILLIAM
#define SOUND_WILLIAM

#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>
#include "ecs/Scene.hpp"

namespace sfml
{
    class SoundGame
    {
        public:
            SoundGame() = default;
            explicit SoundGame(const std::string &path);
            ~SoundGame() = default;
            void setSound(const std::string &path);
            void setLoop(bool loop) {this->_sound.setLoop(loop);};
            void play() { this->_sound.play(); }
            void stop() { this->_sound.stop(); }

        private:
            sf::Sound _sound;
            sf::SoundBuffer _buffer;
    };
}

#endif
