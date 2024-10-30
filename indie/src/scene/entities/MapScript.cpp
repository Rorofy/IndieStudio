/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MapScript
*/

#include "scene/entities/MapScript.hpp"
#include "MapConvert.hpp"
#include "Map.hpp"
#include "scene/entities/BombExploseEvent.hpp"
#include "scene/entities/Player.hpp"
#include "scene/characters/Link.hpp"
#include "scene/characters/Tetra.hpp"
#include "irrlicht/Camera.hpp"

using namespace game;

MapScript::MapScript(indie::Scene &scene, indie::Entity entity, size_t width, size_t height) :
    AScript(scene, entity)
{
    Map map(width, height);
    std::vector<indie::Entity> v(map.getWidth(), 0);

    _map = std::vector<std::vector<indie::Entity>>(map.getHeight(), v);
    mapConverter(scene, map.getMap(), _map);
    scene.getEventBus().subscribe<MapScript, BombExploseEvent>(*this, [this](BombExploseEvent &evt) {
        evt.getBomb().explose(_map);
    });
    spawnPlayers();
    spawnCamera(width, height);
}

void MapScript::spawnPlayers(void)
{
    createPlayer(_scene, std::make_shared<Link>(), findPlayerSpawn(1), 1);
    createPlayer(_scene, std::make_shared<Tetra>(), findPlayerSpawn(2), 2);
}

void MapScript::spawnCamera(size_t width, size_t height)
{
    indie::Entity camera = _scene.spawnEntity();
    irl::Camera &view = _scene.addComponent<irl::Camera>(camera);
    vector3df target = {width/2*1.5f, 0, (height - 2)/2*1.5f};
    vector3df pos = {width/2*1.5f, 18, 2};

    view.init(_scene);
    view.setTarget(target);
    view.setPos(pos);
}

irr::core::vector3df MapScript::findPlayerSpawn(int type)
{
    float y = type == 1 ? 1 : _map.size() - 2;
    float x = type == 1 ? 1 : _map[y].size() - 2;
    float offX = type == 1 ? 1 : -1;
    float offY = type == 1 ? 1 : -1;

    for (; y < _map.size();y += offY)
        for (size_t i = x; i < _map[y].size(); i += offX)
            if (_map[y][i] == 0) return {i*1.5f, 0, y*1.5f};
    return {0, 0, 0};
}

void MapScript::update(void)
{
}

void MapScript::render(void)
{
}

std::vector<std::vector<indie::Entity>> &MapScript::getMap(void)
{
    return _map;
}