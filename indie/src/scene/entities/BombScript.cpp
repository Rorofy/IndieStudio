/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** BombScript
*/

#include "irrlicht/Object3d.hpp"
#include "scene/entities/BombExploseEvent.hpp"
#include "component/Actor.hpp"
#include "component/SoundFX.hpp"
#include "Game.hpp"

using namespace game;

const long BombScript::BOMB_LIFESPAN = 3000;

BombScript::BombScript(indie::Scene &scene, indie::Entity entity, int range) :
    indie::AScript(scene, entity),
    _range(range),
    _counter(BOMB_LIFESPAN)
{
}

void BombScript::update(void)
{
    if (indie::Game::g_delta > _counter) {
        BombExploseEvent event(*this);

        _scene.getEventBus().publish<BombExploseEvent>(event);
    }
    else _counter -= indie::Game::g_delta;
}

void BombScript::render(void)
{
}

void BombScript::explose(std::vector<std::vector<indie::Entity>> &map)
{
    Vector4<int> walls;

    indie::createSoundEntity(_scene, "../assets/sounds/bomb_blow.wav", 1000);
    walls._maxX = exploseLine(map, {_range, 0});
    walls._maxY = exploseLine(map, {0, _range});
    walls._minX = exploseLine(map, {-_range, 0});
    walls._minY = exploseLine(map, {0, -_range});
    exploseActors(map, walls);
    _scene.removeEntity(_entity);
}

int BombScript::exploseLine(std::vector<std::vector<indie::Entity>> &map,
    const irr::core::vector2di &offset)
{
    auto &pos = _scene.getComponent<irl::Object3d>(_entity);
    int x = std::roundf(pos.getX() / 1.5f);
    int y = std::roundf(pos.getZ() / 1.5);
    auto nb = offset.X != 0 ? offset.X : offset.Y;
    indie::Entity target;

    for (size_t i = 0; i <= std::abs(nb) && x >= 0 && y >= 0 && y < map.size() && x < map[0].size(); i++) {
        target = map[y][x];
        if (target != 0) {
            if (!_scene.hasComponent<Destroyable>(target)) return i;
            map[y][x] = 0;
            _scene.getComponent<Destroyable>(target).destroy(_scene, target);
        }
        x += offset.X ? (offset.X > 0 ? 1 : -1) : 0;
        y += offset.Y ?  (offset.Y > 0 ? 1 : -1) : 0;
    }
    return nb;
}

void BombScript::exploseActors(std::vector<std::vector<indie::Entity>> &map,
    const Vector4<int> &range)
{
    auto &actors = _scene.getEntityWith<game::Actor>();
    vector3df pos = _scene.getComponent<irl::Object3d>(_entity).getPos();

    for (auto &i : actors) {
        auto obj = _scene.getComponent<irl::Object3d>(i.first).getPos();
        int x = std::roundf((obj.X - pos.X) / 1.5f);
        int z = std::roundf((obj.Z - pos.Z) / 1.5f);
        int rangeX = std::abs(x > 0 ? range._maxX : range._minX);
        int rangeZ = std::abs(z > 0 ? range._maxY : range._minY);

        if ((std::abs(x) <= rangeX && z == 0) || (std::abs(z) <= rangeZ && x == 0)) {
            _scene.getComponent<game::Actor>(i.first).destroy(_scene, i.first);
            return;
        }
    }
}

int BombScript::getRange(void) const
{
    return _range;
}