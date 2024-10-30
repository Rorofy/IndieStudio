/*
** EPITECH PROJECT, 2021
** yes
** File description:
** yes
*/

#include "sfml/Music.hpp"

using namespace sfml;

MusicGame::MusicGame(const std::string &file)
{
    this->_music.openFromFile(file);
}

void MusicGame::setMusic(const std::string &file)
{
    this->_music.openFromFile(file);
}

void MusicGame::setVolume(const int volume)
{
    this->_music.setVolume(volume);
}

void MusicGame::setLoop(const bool loop)
{
    this->_music.setLoop(loop);
}
