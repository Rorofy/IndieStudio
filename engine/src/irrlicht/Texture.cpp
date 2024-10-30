/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Texture
*/

#include "Game.hpp"
#include "irrlicht/Texture.hpp"

using namespace irl;

Texture::Texture(const std::string &path, int offsetX, int offsetY, int width, int height) :
    _path(path),
    _rect{offsetX, offsetY, width, height}
{
    _texture = indie::getVideoDriver()->getTexture(path.c_str());
}

Texture::~Texture()
{
}

const std::string &Texture::getPath() const
{
    return this->_path;
}

const core::rect<s32> &Texture::getRect() const
{
    return this->_rect;
}

const video::ITexture *Texture::getTexture() const
{
    return this->_texture;
}
