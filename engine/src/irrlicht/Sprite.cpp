/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Sprite
*/

#include "Game.hpp"
#include "irrlicht/Sprite.hpp"

using namespace irl;

Sprite::Sprite() :
    _currentFrame(0),
    _framesCounter(0),
    _framesSpeed(1),
    _opacity(255)
{
}

void Sprite::appendTexture(Texture &texture)
{
    this->_sprite.push_back(texture);
}

void Sprite::displaySprite(float x, float y, std::uint32_t opacity)
{
    if (this->_framesCounter >= (60/this->_framesSpeed)) {
            this->_framesCounter = 0;
            this->_currentFrame++;

            if (this->_currentFrame >= this->_sprite.size())
                this->_currentFrame = 0;
    }
    indie::getVideoDriver()->draw2DImage(this->_sprite[this->_currentFrame].getTexture(),
        core::position2d<s32>(x,y),
        this->_sprite[this->_currentFrame].getRect(), NULL,
        video::SColor(opacity, 255, 255, 255), true);
}