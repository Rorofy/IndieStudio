/*
** EPITECH PROJECT, 2021
** yes
** File description:
** yes
*/

#include "sfml/Sound.hpp"
#include "component/Lifespan.hpp"

using namespace sfml;
using namespace indie;

SoundGame::SoundGame(const std::string &file)
{
    this->_buffer.loadFromFile(file);
    this->_sound.setBuffer(this->_buffer);
}

void SoundGame::setSound(const std::string &file)
{
    this->_buffer.loadFromFile(file);
    this->_sound.setBuffer(this->_buffer);
}