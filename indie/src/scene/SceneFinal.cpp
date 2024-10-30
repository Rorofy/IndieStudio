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
#include "scene/entities/Head.hpp"
#include "scene/characters/Link.hpp"
#include "scene/characters/Tetra.hpp"
#include "component/Actor.hpp"
#include "irrlicht/Camera.hpp"
#include "irrlicht/Sprite.hpp"
#include "Position.hpp"
#include "ui/Button.hpp"
#include "irrlicht/Text.hpp"
#include "component/Script.hpp"
#include "ui/ScriptKeybind.hpp"

using namespace game;

static void createCamera(indie::Scene &scene)
{
    indie::Entity camera = scene.spawnEntity();
    irl::Camera &view = scene.addComponent<irl::Camera>(camera);
    vector3df target = {0, 0, 0};
    vector3df pos = {0, 1, -5};

    view.init(scene);
    view.setTarget(target);
    view.setPos(pos);
}

static void createDummy(indie::Scene &scene, std::shared_ptr<ACharacter> character,
    const irr::core::vector3df &pos, int win)
{
    indie::Entity player = scene.spawnEntity();
    irl::Object3d &obj = scene.addComponent<irl::Object3d>(player);
    auto &actor = scene.addComponent<game::Actor>(player);

    character->init(obj);
    obj.playAnimation("idle");
    obj.setPos(pos);
    obj.playAnimation(win ? "win" : "defeat");
}

std::shared_ptr<indie::Scene> game::createSceneFinal(int winnerType)
{
    auto scene = indie::Game::g_instance->createScene();
    irr::core::vector3df link;
    irr::core::vector3df tetra;

    if (winnerType == 1) {
        link = {0, 1.6f, 0};
        tetra = {-2, 0, 0};
    }
    else {
        link = {-2, 0, 0};
        tetra = {0, 1.7f, 0};
    }
    game::createHead(*scene, {0, 0, 0});
    createCamera(*scene);
    createDummy(*scene, std::make_shared<Link>(), link, winnerType == 1);
    createDummy(*scene, std::make_shared<Tetra>(), tetra, winnerType == 2);

    indie::Entity bg = scene->spawnEntity();
    irl::Texture bgTexture = irl::Texture("../assets/ui/grass.png", 0, 0, 1920, 1080);
    irl::Sprite &bgSprite = scene->addComponent<irl::Sprite>(bg);
    game::Position &bgPos = scene->addComponent<game::Position>(bg);
    indie::Entity menu = scene->spawnEntity();
    irl::Text &menuText = scene->addComponent<irl::Text>(menu);
    game::Position &menuPos = scene->addComponent<game::Position>(menu);
    game::Button &menuButton = scene->addComponent<game::Button>(menu);
    indie::Entity quit = scene->spawnEntity();
    irl::Text &quitText = scene->addComponent<irl::Text>(quit);
    game::Position &quitPos = scene->addComponent<game::Position>(quit);
    game::Button &quitButton = scene->addComponent<game::Button>(quit);

    bgPos.setPos(0, 0, 0);
    bgSprite.appendTexture(bgTexture);
    menuText.setString("Main menu");
    menuText.setFont("../assets/ui/SherwoodRegular.png");
    menuPos.setPos(835, 600, 0);
    menuButton.setHeight(43);
    menuButton.setWidth(240);
    menuButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
        indie::Game::g_instance->removeScene(scene);
        game::createSceneMenu();
    });
    quitText.setString("Quit");
    quitText.setFont("../assets/ui/SherwoodRegular.png");
    quitPos.setPos(900, 700, 0);
    quitButton.setHeight(43);
    quitButton.setWidth(100);
    quitButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
       indie::getDevice()->closeDevice();
    });
    return scene;
}