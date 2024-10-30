/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** Scene
*/

#include <iostream>
#include "ecs/Scene.hpp"
#include "Game.hpp"
#include "ecs/ComponentMap.hpp"
#include "event/EntityRemove.hpp"
#include "irrlicht/RigidBody.hpp"

using namespace indie;

Scene::Scene(std::shared_ptr<AComponentMapFactory> compMap) :
    _compMap(compMap),
    _eventBus(std::make_unique<EventBus>())
{
}

Scene::~Scene()
{
}

void Scene::init()
{
    for (auto &i : _systems)
        i->init();
}

void Scene::update()
{
    for (auto &i : _systems)
        i->update();
    post();
}

void Scene::render()
{
    for (auto &i : _systems)
        i->render();
}

void Scene::post(void)
{
    auto entity = _deads.begin();

    for (auto &manager : _compManagers) manager->update();
    while (entity != _deads.end()) {
        EntityRemove event(*entity);
        std::shared_ptr<AComponentMap> old = _maskMap[*entity]->clone();

        if (hasComponent<irl::RigidBody>(*entity)) indie::Game::g_instance->getSelector()->removeTriangleSelector(getComponent<irl::RigidBody>(*entity).getSelector());

        _eventBus->publish(event);
        _maskMap[*entity]->clear();
        updateSystems(*entity, *old);
        _maskMap.erase(*entity);
        for (std::size_t i = 0; i < _compManagers.back()->getComponentId(); i++)
            if (old->get(i))
                _compManagers[i]->remove(*entity);
        entity = _deads.erase(entity);
    }    
}

Entity Scene::spawnEntity()
{
    Entity ent = _entityManager.spawnEntity();

    _maskMap[ent] = _compMap->factory();
    return ent;
}

void Scene::removeEntity(Entity entity)
{
    _deads.insert(entity);
}

void Scene::updateSystems(Entity e, AComponentMap &old)
{
    std::unique_ptr<AComponentMap> &entityMask = _maskMap[e];

    for (auto &i : _systems) {
        AComponentMap &signature = i->getSignature();

        if (entityMask->oldContain(old, signature))
            i->trackEntity(e);
        else if (entityMask->oldRemove(old, signature))
            i->untrackEntity(e);
    }
}

void Scene::registerComponentManager(std::unique_ptr<AComponentManager> manager) {
    _compManagers.push_back(std::move(manager));
}

void Scene::registerSystem(std::unique_ptr<ASystem> system) {
    _systems.push_back(std::move(system));
}

EventBus &Scene::getEventBus() const
{
    return *_eventBus;
}