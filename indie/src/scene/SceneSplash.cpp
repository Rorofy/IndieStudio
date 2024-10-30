/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SceneSplash
*/

#include "scene/Scenes.hpp"
#include "scene/SceneGame.hpp"
#include "irrlicht/Sprite.hpp"
#include "Position.hpp"
#include "ui/Button.hpp"
#include "irrlicht/Text.hpp"
#include "component/Lifespan.hpp"
#include "component/SoundFX.hpp"
#include "Game.hpp"

std::shared_ptr<indie::Scene> game::createSceneSplash(void)
{
    std::shared_ptr<indie::Scene> scene = indie::Game::g_instance->createScene();

    indie::Entity background = scene->spawnEntity();
    indie::Entity link = scene->spawnEntity();
    irl::Texture linkTexture = irl::Texture("../assets/ui/potLink.png", 0, 0, 593, 860);
    irl::Texture backgroundTexture = irl::Texture("../assets/ui/Black.png", 0, 0, 1920, 1080);
    game::Position &backgroundPos = scene->addComponent<game::Position>(background);
    irl::Sprite &backgroundSprite = scene->addComponent<irl::Sprite>(background);
    indie::Lifespan &lifespan = scene->addComponent<indie::Lifespan>(background);
    game::Position &linkPos = scene->addComponent<game::Position>(link);
    irl::Sprite &linkSprite = scene->addComponent<irl::Sprite>(link);

    backgroundPos.setPos(0, 0, 0);
    backgroundSprite.appendTexture(backgroundTexture);
    linkPos.setPos(800, 200, 0);
    linkSprite.appendTexture(linkTexture);
    lifespan.setLifespan(2000);
    lifespan.setCallback([](indie::Scene &scene, indie::Entity entity) {
        auto back = indie::Game::g_instance->createScene();

        back->addComponent<indie::SoundFX>(back->spawnEntity()).setMusic("../assets/sounds/music.wav");
        indie::Game::g_instance->removeScene(scene);
        game::createSceneMenu();
    });
    return scene;
}
