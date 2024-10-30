/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Actor
*/

#include "component/Actor.hpp"

using namespace game;

Actor::Actor(int value) :
    Destroyable(value)
{
}

void Actor::setPowerup(const std::string name, bool value)
{
    _powerups[name] = value;
}

bool Actor::getPowerup(const std::string name) const
{
    return _powerups.at(name);
}