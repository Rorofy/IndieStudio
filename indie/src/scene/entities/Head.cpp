/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Head
*/

#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>
#include "Game.hpp"
#include "scene/entities/Head.hpp"
#include "irrlicht/Object3d.hpp"
#include "IndieRandom.hpp"

indie::Entity game::createHead(indie::Scene &scene, vector3df pos)
{
    indie::Entity player = scene.spawnEntity();
    irl::Object3d &model = scene.addComponent<irl::Object3d>(player);

    model.setMesh("../assets/models/head.b3d");
    model.setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/head.png"));
    model.setPos(pos);
    return player;
}