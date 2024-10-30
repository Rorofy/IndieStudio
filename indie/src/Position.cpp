/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Position
*/

#include "Position.hpp"

using namespace game;

void Position::setPos(int x, int y, int z) {
    _x = x;
    _y = y;
    _z = z;
}
const int &Position::getX() const
{
    return _x;
}

const int &Position::getY() const
{
    return _y;
}

const int &Position::getZ() const
{
    return _z;
}