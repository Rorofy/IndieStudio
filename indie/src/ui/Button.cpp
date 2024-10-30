/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Button
*/

#include "ui/Button.hpp"

using namespace game;

void Button::setHitbox(int width, int height)
{
    _width = width;
    _height = height;
}

void Button::setHeight(int height)
{
    _height = height;
}

void Button::setName(const std::string &name)
{
    _name = name;
}

void Button::setValue(const std::string &name)
{
    _value = name;
}

void Button::setOnClick(std::function<void (indie::Scene &, indie::Entity)> onClick)
{
    _onClick = onClick;
    _click = true;
}

void Button::setWidth(int width)
{
    _width = width;
}

bool Button::isClickable(void) const
{
    return _click;
}

int Button::getHeight(void) const
{
    return _height;
}

int Button::getWidth(void) const
{
    return _width;
}

const std::string &Button::getName(void) const
{
    return _name;
}

const std::string &Button::getValue(void) const
{
    return _value;
}

const std::function<void (indie::Scene &, indie::Entity)> &Button::getOnClick() const
{
    return _onClick;
}