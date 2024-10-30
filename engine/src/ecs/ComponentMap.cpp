/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** ComponentMap
*/

#include "ecs/ComponentMap.hpp"

using namespace indie;

bool AComponentMap::oldContain(AComponentMap &old, AComponentMap &map) {
    return !old.contain(map) && contain(map);
}

bool AComponentMap::oldRemove(AComponentMap &old, AComponentMap &map) {
    return old.contain(map) && !contain(map);
}