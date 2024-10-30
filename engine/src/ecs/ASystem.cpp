/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** ASystem
*/

#include <algorithm>
#include "ecs/ASystem.hpp"

using namespace indie;

ASystem::ASystem(Scene &scene) :
    _scene(scene)
{
}

void ASystem::trackEntity(Entity entity)
{
    _entityRegistry.push_back(entity);
}

void ASystem::untrackEntity(Entity entity)
{
    _entityRegistry.erase(std::remove(_entityRegistry.begin(), _entityRegistry.end(), entity));
}

void ASystem::setSignature(std::unique_ptr<AComponentMap> map)
{
    _compSignature = std::move(map);
}

AComponentMap &ASystem::getSignature(void)
{
    return *_compSignature;
}