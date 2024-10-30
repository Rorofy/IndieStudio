/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SceneMenu
*/

#include "scene/Scenes.hpp"
#include "scene/SceneGame.hpp"
#include "irrlicht/Sprite.hpp"
#include "irrlicht/Object3d.hpp"
#include "irrlicht/Camera.hpp"
#include "Position.hpp"
#include "ui/Button.hpp"
#include "irrlicht/Text.hpp"

static void create3dCtx(indie::Scene &scene)
{
    indie::Entity camera = scene.spawnEntity();
    irl::Camera &view = scene.addComponent<irl::Camera>(camera);
    vector3df target = {0, 10, 50};
    vector3df pos = {0, 20, 30};

    auto &s = indie::getSceneManager();
    const irr::scene::IGeometryCreator *geomentryCreator = s.getGeometryCreator();
    irr::video::SMaterial *mat = new irr::video::SMaterial();

    mat->setTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/water.jpg"));
    irr::scene::IMesh* plane = geomentryCreator->createPlaneMesh(irr::core::dimension2d<irr::f32>(5, 5), irr::core::dimension2d<irr::u32>(50, 50), mat, {50, 50});
    plane->setMaterialFlag(irr::video::EMF_LIGHTING, false);    //This is important
    plane->setMaterialFlag(video::EMF_BACK_FACE_CULLING, false);
    plane->setMaterialFlag(video::EMF_FRONT_FACE_CULLING, false);
    auto ground = s.addMeshSceneNode(plane);
    ground->setAutomaticCulling(false);
    ground->setPosition({0, 0, 0});

    view.init(scene);
    view.setTarget(target);
    view.setPos(pos);
}

std::shared_ptr<indie::Scene> game::createSceneMenu(void)
{
    std::shared_ptr<indie::Scene> menu = indie::Game::g_instance->createScene();

    indie::Entity bg = menu->spawnEntity();
    indie::Entity logo = menu->spawnEntity();
    indie::Entity start = menu->spawnEntity();
    indie::Entity exit = menu->spawnEntity();
    indie::Entity settings = menu->spawnEntity();
    indie::Entity load = menu->spawnEntity();
    irl::Texture logoTexture = irl::Texture("../assets/ui/title.png", 0, 0, 800, 350);
    irl::Texture bgTexture = irl::Texture("../assets/ui/grass.png", 0, 0, 1920, 1080);
    irl::Text &startText = menu->addComponent<irl::Text>(start);
    game::Position &startPos = menu->addComponent<game::Position>(start);
    game::Button &startButton = menu->addComponent<game::Button>(start);
    game::Position &settingsPos = menu->addComponent<game::Position>(settings);
    irl::Text &settingsText = menu->addComponent<irl::Text>(settings);
    game::Button &settingsButton = menu->addComponent<game::Button>(settings);
    game::Position &loadPos = menu->addComponent<game::Position>(load);
    irl::Text &loadText = menu->addComponent<irl::Text>(load);
    game::Button &loadButton = menu->addComponent<game::Button>(load);
    irl::Text &exitText = menu->addComponent<irl::Text>(exit);
    game::Position &exitPos = menu->addComponent<game::Position>(exit);
    game::Button &exitButton = menu->addComponent<game::Button>(exit);
    irl::Sprite &bgSprite = menu->addComponent<irl::Sprite>(bg);
    game::Position &bgPos = menu->addComponent<game::Position>(bg);
    irl::Sprite &logoSprite = menu->addComponent<irl::Sprite>(logo);
    game::Position &logoPos = menu->addComponent<game::Position>(logo);

    bgPos.setPos(0, 0, 0);
    bgSprite.appendTexture(bgTexture);
    logoPos.setPos(600, 150, 0);
    logoSprite.appendTexture(logoTexture);
    startPos.setPos(900, 550, 0);
    startText.setString("Start");
    startText.setFont("../assets/ui/SherwoodRegular.png");
    startButton.setHeight(43);
    startButton.setWidth(140);
    startButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
        indie::Game::g_instance->removeScene(scene);
        game::createSceneGame();
    });
    settingsPos.setPos(880, 750, 0);
    settingsText.setString("Settings");
    settingsText.setFont("../assets/ui/SherwoodRegular.png");
    settingsButton.setHeight(43);
    settingsButton.setWidth(190);
    settingsButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
        indie::Game::g_instance->removeScene(scene);
        game::createSceneSettings();
    });
    loadPos.setPos(850, 650, 0);
    loadText.setString("Load game");
    loadText.setFont("../assets/ui/SherwoodRegular.png");
    loadButton.setHeight(43);
    loadButton.setWidth(240);
    loadButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
        indie::getDevice()->closeDevice();
    });
    exitPos.setPos(910, 850, 0);
    exitText.setString("Quit");
    exitText.setFont("../assets/ui/SherwoodRegular.png");
    exitButton.setHeight(43);
    exitButton.setWidth(100);
    exitButton.setOnClick([](indie::Scene &scene, indie::Entity entity) {
        indie::getDevice()->closeDevice();
    });
    return menu;
}