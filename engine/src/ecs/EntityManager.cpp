/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL]
** File description:
** EntityManager
*/

#include <string>
#include "ecs/EntityManager.hpp"

using namespace indie;

EntityManager::EntityManager() :
    _lastId(1)
{
}

EntityManager::~EntityManager()
{
}

Entity EntityManager::spawnEntity(void)
{
    return _lastId++;
}