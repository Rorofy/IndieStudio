/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Rock
*/

#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>
#include "Game.hpp"
#include "scene/entities/Rock.hpp"
#include "irrlicht/Object3d.hpp"
#include "irrlicht/Transform.hpp"
#include "irrlicht/RigidBody.hpp"
#include "IndieRandom.hpp"

using namespace game;

static indie::Entity createRockImpl(indie::Scene &scene, vector3df pos,
    const std::string &modelPath, const std::string &path)
{
    indie::Entity player = scene.spawnEntity();
    irl::Object3d &obj = scene.addComponent<irl::Object3d>(player);
    irl::RigidBody &rigid = scene.addComponent<irl::RigidBody>(player);

    obj.setMesh(modelPath);
    obj.setPos(pos.X, pos.Y, pos.Z);
    obj.setMaterialTexture(0, indie::Game::g_instance->getTexture(path.c_str()));
    rigid.init(obj);
    return player;
}

indie::Entity game::createRock(indie::Scene &scene, vector3df pos)
{
    return createRockImpl(scene, pos, "../assets/models/rock.b3d",
        "../assets/textures/models/map/mi_rock_01_alb.png");
}

indie::Entity game::createRock2(indie::Scene &scene, vector3df pos)
{
    return createRockImpl(scene, pos, "../assets/models/rock2.b3d",
    "../assets/textures/models/map/mi_caverock_01_alb.png");
}