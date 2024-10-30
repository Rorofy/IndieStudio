/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemScript
*/

#include "system/SystemScript.hpp"
#include "Position.hpp"
#include "component/Script.hpp"
#include "ecs/Scene.hpp"

using namespace indie;

SystemScript::SystemScript(Scene &scene) :
    ASystem(scene)
{
}

void SystemScript::init()
{
    trackComponent<indie::Script>();
}

void SystemScript::update()
{
    for (auto e : _entityRegistry) {
        auto &script = _scene.getComponent<indie::Script>(e);
        script.getScript().update();
    }
}

void SystemScript::render()
{
    for (auto e : _entityRegistry) {
        auto &script = _scene.getComponent<indie::Script>(e);
        script.getScript().render();
    }
}