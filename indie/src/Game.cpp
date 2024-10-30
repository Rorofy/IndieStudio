/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** test
*/

#include <iostream>
#include "Game.hpp"
#include "event/EventBus.hpp"
#include "ui/Button.hpp"
#include "ui/SystemButton.hpp"
#include "ui/SystemText.hpp"
#include "system/SystemSprite.hpp"
#include "system/SystemSprite.hpp"
#include "system/SystemPowerup.hpp"
#include "system/SystemLifespan.hpp"
#include "system/SystemController.hpp"
#include "Position.hpp"
#include "component/Controller.hpp"
#include "component/Destroyable.hpp"
#include "component/Actor.hpp"
#include "irrlicht/RigidBody.hpp"
#include "irrlicht/Camera.hpp"
#include "irrlicht/Object3d.hpp"
#include "irrlicht/Sprite.hpp"
#include "irrlicht/Text.hpp"
#include "component/SoundFX.hpp"
#include "irrlicht/ParticleFX.hpp"
#include "component/Script.hpp"
#include "component/Lifespan.hpp"
#include "component/Powerup.hpp"
#include "system/SystemScript.hpp"
#include "scene/Scenes.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

static indie::Game &initGame(void)
{
    indie::Game::g_instance = std::make_unique<indie::Game>();
    indie::Game &game = *indie::Game::g_instance;

    game.initComponent<15>();
    game.registerComponent<irl::Object3d>();
    game.registerComponent<game::Position>();
    game.registerComponent<irl::Sprite>();
    game.registerComponent<irl::Text>();
    game.registerComponent<game::Button>();
    game.registerComponent<irl::RigidBody>();
    game.registerComponent<game::Actor>();
    game.registerComponent<game::Destroyable>();
    game.registerComponent<indie::Script>();
    game.registerComponent<indie::Lifespan>();
    game.registerComponent<indie::SoundFX>();
    game.registerComponent<irl::ParticleFX>();
    game.registerComponent<irl::Camera>();
    game.registerComponent<game::Controller>();
    game.registerComponent<game::Powerup>();
    game.registerSystem<game::SystemButton>();
    game.registerSystem<indie::SystemScript>();
    game.registerSystem<indie::SystemLifespan>();
    game.registerSystem<game::SystemSprite>();
    game.registerSystem<game::SystemText>();
    game.registerSystem<game::SystemController>();
    game.registerSystem<game::SystemPowerup>();
    return game;
}

static void startGame(void)
{
    indie::Game &game = initGame();

    game::createSceneSplash();
    game.start();
}

int main(void)
{
    startGame();
}