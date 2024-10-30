/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SceneDevRoom
*/

#include "scene/Scenes.hpp"
#include "Position.hpp"
#include "scene/entities/Player.hpp"
#include "scene/characters/Tetra.hpp"
#include "scene/entities/Rock.hpp"
#include "scene/entities/Pot.hpp"
#include "irrlicht/Camera.hpp"
#include "Map.hpp"
#include "MapConvert.hpp"

std::shared_ptr<indie::Scene> game::createSceneDevRoom(void)
{
    std::shared_ptr<indie::Scene> scene = indie::Game::g_instance->createScene();
    indie::Entity player = game::createPlayer(*scene, std::make_shared<Tetra>(), {0, 0, 0}, 1);
    indie::Entity camera = scene->spawnEntity();
    indie::Entity rock = game::createRock(*scene, {0, 0, 0});
    indie::Entity rock2 = game::createRock2(*scene, {2, 0, 0});
    irl::Camera &view = scene->addComponent<irl::Camera>(camera);
    vector3df target = {0, 0, 0};
    vector3df rotation = {0, 0, 10};
    vector3df pos = {10, 10, 10};
    Map map(10, 10);

    view.init(*scene);
    view.setTarget(target);
    view.setRotation(rotation);
    view.setPos(pos);
    for (size_t i = 0; i < 5; i++) game::createPot(*scene, {0, 0, 2.0f + 1.0f * i}, 0);
    return scene;
}