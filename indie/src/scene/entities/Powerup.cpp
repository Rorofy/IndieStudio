/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Powerup
*/

#include "Game.hpp"
#include "scene/entities/Powerups.hpp"
#include "component/Powerup.hpp"
#include "irrlicht/Object3d.hpp"

indie::Entity game::createShield(indie::Scene &scene, const irr::core::vector3df &pos)
{
    indie::Entity shield = scene.spawnEntity();
    irl::Object3d &model = scene.addComponent<irl::Object3d>(shield);
    game::Powerup &powerup = scene.addComponent<game::Powerup>(shield);

    powerup.setName("shield");
    model.setMesh("../assets/models/shield.b3d");
    model.setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/map/shield.png"));
    model.setPos(pos);
    return shield;
}

indie::Entity game::createBigBomb(indie::Scene &scene, const irr::core::vector3df &pos)
{
    indie::Entity shield = scene.spawnEntity();
    irl::Object3d &model = scene.addComponent<irl::Object3d>(shield);
    game::Powerup &powerup = scene.addComponent<game::Powerup>(shield);

    powerup.setName("bigbomb");
    model.setMesh("../assets/models/bigbomb.b3d");
    model.setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/map/bigbomb.png"));
    model.setPos(pos);
    return shield;
}

indie::Entity game::createDoubleBomb(indie::Scene &scene, const irr::core::vector3df &pos)
{
    indie::Entity doublebomb = scene.spawnEntity();
    irl::Object3d &model = scene.addComponent<irl::Object3d>(doublebomb);
    game::Powerup &powerup = scene.addComponent<game::Powerup>(doublebomb);

    powerup.setName("doublebomb");
    model.setMesh("../assets/models/doublebomb.b3d");
    for (size_t i = 0; i < model.get3dObject()->getMaterialCount(); i++)
        model.get3dObject()->getMaterial(i).setTexture(0,
            indie::Game::g_instance->getTexture("../assets/textures/models/map/doublebomb.png"));
    model.setPos(pos);
    return doublebomb;
}

indie::Entity game::createSlowBoot(indie::Scene &scene, const irr::core::vector3df &pos)
{
    indie::Entity slowboot = scene.spawnEntity();
    irl::Object3d &model = scene.addComponent<irl::Object3d>(slowboot);
    game::Powerup &powerup = scene.addComponent<game::Powerup>(slowboot);

    powerup.setName("slowboot");
    model.setMesh("../assets/models/slowboot.b3d");
    model.setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/map/slowboot.png"));
    model.setMaterialTexture(1, indie::Game::g_instance->getTexture("../assets/textures/models/map/slowboot_iron.png"));
    model.setPos(pos);
    return slowboot;
}

indie::Entity game::createSpeedBoot(indie::Scene &scene, const irr::core::vector3df &pos)
{
    indie::Entity speedboot = scene.spawnEntity();
    irl::Object3d &model = scene.addComponent<irl::Object3d>(speedboot);
    game::Powerup &powerup = scene.addComponent<game::Powerup>(speedboot);

    powerup.setName("speedboot");
    model.setMesh("../assets/models/speedboot.b3d");
    model.setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/map/speedboot.png"));
    model.setMaterialTexture(1, indie::Game::g_instance->getTexture("../assets/textures/models/map/speedboot_gold.png"));
    model.setPos(pos);
    return speedboot;
}