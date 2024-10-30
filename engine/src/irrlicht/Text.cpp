/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Text
*/

#include "Game.hpp"
#include "irrlicht/Text.hpp"

using namespace irl;

Text::Text() :
    _str("Default Text"),
    _color(255, 0, 0, 0),
    _font(NULL),
    _hcenter(false),
    _vcenter(false)
{
}

Text::~Text()
{
}

void Text::renderText(rect<s32> &position)
{
    _font->draw(_str, position, _color, _hcenter, _vcenter, NULL);
}

void Text::setString(const stringw &str)
{
    _str = str;
    
}

void Text::setFont(const std::string &path)
{
    _font = indie::getGuiEnv().getFont(path.c_str());
    if (_font == NULL) throw new std::exception();
}

void Text::setCenterV(bool center)
{
    _vcenter = center;
}

void Text::setCenterH(bool center)
{
    _hcenter = center;
}

void Text::setColor(u32 r, u32 g, u32 b, u32 a)
{
    _color.setRed(r);
    _color.setGreen(g),
    _color.setBlue(b);
    _color.setAlpha(a);
}