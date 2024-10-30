/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL]
** File description:
** Script
*/

#include "component/Script.hpp"

using namespace indie;

AScript::AScript(indie::Scene &scene, indie::Entity entity) :
    _scene(scene),
    _entity(entity)
{
}


void Script::setScript(std::unique_ptr<AScript> script)
{
    _script = std::move(script);
}

AScript &Script::getScript(void)
{
    return *_script;
}