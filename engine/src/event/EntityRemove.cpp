/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** EntityRemove
*/

#include "event/EntityRemove.hpp"

using namespace indie;

EntityRemove::EntityRemove(Entity entity) :
    _entity(entity)
{
}

Entity EntityRemove::getEntity(void) const
{
    return _entity;
}