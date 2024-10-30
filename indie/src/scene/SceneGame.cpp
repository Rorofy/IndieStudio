/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SceneGame
*/

#include "Game.hpp"
#include "scene/Scenes.hpp"
#include "scene/SceneGame.hpp"
#include "scene/entities/MapScript.hpp"
#include "component/Controller.hpp"
#include "irrlicht/Object3d.hpp"
#include "ui/Pause.hpp"
#include "irrlicht/Sprite.hpp"
#include "irrlicht/Object3d.hpp"
#include "irrlicht/Camera.hpp"
#include "Position.hpp"
#include "ui/Button.hpp"
#include "irrlicht/Text.hpp"

using namespace game;

std::shared_ptr<indie::Scene> game::createSceneGame(void)
{
    auto scene = indie::Game::g_instance->createScene();
    indie::Entity bg = scene->spawnEntity();
    irl::Texture bgTexture = irl::Texture("../assets/ui/grass.png", 0, 0, 1920, 1080);
    irl::Sprite &bgSprite = scene->addComponent<irl::Sprite>(bg);
    game::Position &bgPos = scene->addComponent<game::Position>(bg);
    indie::Entity map = scene->spawnEntity();
    auto &script = scene->addComponent<indie::Script>(map);
    indie::Entity pauser = scene->spawnEntity();
    auto &controller = scene->addComponent<Controller>(pauser);
    indie::Entity water = scene->spawnEntity();
    auto &obj = scene->addComponent<irl::Object3d>(water);

    bgPos.setPos(0, 0, 0);
    bgSprite.appendTexture(bgTexture);
    obj.setMesh("../assets/models/water.obj");
    obj.setPos({2, 5, 0});
    obj.get3dObject()->setAutomaticCulling(false);
    obj.get3dObject()->setScale({0.1, 0.1, 0.1});
    obj.setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/water.jpg"));
    controller.addStaticAction("pause", {[](indie::Scene &scene, indie::Entity &pause) {
        displayPauseMenu(scene);
    }}, 2000);
    script.setScript(std::make_unique<MapScript>(*scene, map, 15, 15));
    return scene;
}