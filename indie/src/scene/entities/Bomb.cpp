/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Bomb
*/

#include "Game.hpp"
#include "scene/entities/Bomb.hpp"
#include "scene/entities/BombScript.hpp"
#include "irrlicht/Object3d.hpp"
#include "IndieRandom.hpp"
#include "component/Destroyable.hpp"
#include "component/SoundFX.hpp"

indie::Entity game::createBomb(indie::Scene &scene, const vector3df &pos, int range)
{
    indie::Entity bomb = scene.spawnEntity();
    irl::Object3d &model = scene.addComponent<irl::Object3d>(bomb);
    indie::Script &script = scene.addComponent<indie::Script>(bomb);

    scene.addComponent<game::Destroyable>(bomb);
    script.setScript(std::make_unique<game::BombScript>(scene, bomb, range));
    model.setMesh("../assets/models/bomb.b3d");
    model.setPos(pos);
    indie::createSoundEntity(scene, "../assets/sounds/bomb_light.wav", 1000);
    indie::createSoundEntity(scene, "../assets/sounds/bomb_fuse.wav", BombScript::BOMB_LIFESPAN, true);
    return bomb;
}