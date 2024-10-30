/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemPowerup
*/

#include "system/SystemPowerup.hpp"
#include "component/Powerup.hpp"
#include "irrlicht/Object3d.hpp"
#include "component/SoundFX.hpp"
#include "component/Actor.hpp"

using namespace game;

SystemPowerup::SystemPowerup(indie::Scene &scene) :
    ASystem(scene)
{
}

void SystemPowerup::init()
{
    trackComponent<game::Powerup>();
    trackComponent<irl::Object3d>();
}

void SystemPowerup::update()
{
    auto &actors = _scene.getEntityWith<game::Actor>();

    for (auto actor : actors)
        for (auto powerup : _entityRegistry)
            handleActor(powerup, actor.first);
}

void SystemPowerup::render()
{
}

void SystemPowerup::handleActor(indie::Entity powerup, indie::Entity actor)
{
    auto &powerupObj = _scene.getComponent<irl::Object3d>(powerup);
    auto &actorObj = _scene.getComponent<irl::Object3d>(actor);

    if (doActorCollide(powerupObj, actorObj)) {
        auto &powerupComp = _scene.getComponent<game::Powerup>(powerup);
        auto &actorComp = _scene.getComponent<game::Actor>(actor);

        indie::createSoundEntity(_scene, "../assets/sounds/item.wav", 1000);
        actorComp.setPowerup(powerupComp.getName(), true);
        _scene.removeEntity(powerup);
    }
}

bool SystemPowerup::doActorCollide(const irl::Object3d &powerup,
    const irl::Object3d &actor)
{
    int actorX = std::roundf(actor.getX() / 1.5f);
    int actorY = std::roundf(actor.getZ() / 1.5);
    int powerupX = std::roundf(powerup.getX() / 1.5f);
    int powerupY = std::roundf(powerup.getZ() / 1.5);

    return actorX == powerupX && actorY == powerupY;
}