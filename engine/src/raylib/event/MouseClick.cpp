/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MouseClick
*/

#include "raylib/event/MouseClick.hpp"

using namespace ray;

MouseClick::MouseClick(int x, int y) :
    _x(x),
    _y(y)
{

}

int MouseClick::getX() const
{
    return _x;
}

int MouseClick::getY() const
{
    return _y;
}