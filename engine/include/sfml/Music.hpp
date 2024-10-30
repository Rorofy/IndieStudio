/*
** EPITECH PROJECT, 2021
** yes
** File description:
** yes
*/

#ifndef MUSIC
#define MUSIC

#include <SFML/Audio.hpp>
#include <iostream>

namespace sfml
{
    class MusicGame
    {
        public:
            MusicGame() = default;
            explicit MusicGame(const std::string &file);
            ~MusicGame() = default;
            void setMusic(const std::string &file);
            void play() { this->_music.play(); }
            void stop() { this->_music.stop(); }
            void setVolume(const int volume);
            void setLoop(bool loop);

        private:
            sf::Music _music;
    };
}
#endif
