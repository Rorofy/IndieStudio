/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemLifespan
*/

#include "system/SystemLifespan.hpp"
#include "Game.hpp"
#include "component/Lifespan.hpp"
#include "ecs/Scene.hpp"

using namespace indie;

SystemLifespan::SystemLifespan(Scene &scene) :
    ASystem(scene)
{
}

void SystemLifespan::init()
{
    trackComponent<indie::Lifespan>();
}

void SystemLifespan::update()
{
    for (auto e : _entityRegistry) {
        auto &lifespan = _scene.getComponent<indie::Lifespan>(e);

        if (Game::g_delta >= lifespan.getLifespan()) {
            if (lifespan.haveCallback()) lifespan.getCallback()(_scene, e);
            _scene.removeEntity(e);
        }
        else lifespan.decrease(Game::g_delta);
    }
}

void SystemLifespan::render()
{
}