/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Destroyable
*/

#include "component/Destroyable.hpp"

using namespace game;

void Destroyable::setCallback(std::unique_ptr<IDestroyCallback> callback)
{
    _callback = std::move(callback);
}

bool Destroyable::haveCallback(void) const
{
    return _callback != nullptr;
}

const Destroyable::IDestroyCallback &Destroyable::getCallback(void) const
{
    return *_callback;
}

void Destroyable::destroy(indie::Scene &scene, indie::Entity entity) const
{
    if (this->haveCallback())
        if (!_callback->destroy(scene, entity)) return;
    scene.removeEntity(entity);
}