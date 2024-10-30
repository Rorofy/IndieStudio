/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Tetra
*/

#include "scene/characters/Tetra.hpp"
#include "Game.hpp"

using namespace game;

void Tetra::init(irl::Object3d &model)
{
    auto &game = indie::Game::g_instance;
    irl::Object3d::Animation idle(0, 276);
    irl::Object3d::Animation run(395, 413);
    irl::Object3d::Animation drop(413, 496, false, 180);
    irl::Object3d::Animation death(497, 585, false);
    irl::Object3d::Animation win(684, 737);
    irl::Object3d::Animation defeat(738, 784);

    model.setMesh("../assets/models/tetra.b3d");
    model.setMaterialTexture(0, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(1, game->getTexture("../assets/textures/models/tetra/eye1.png"));
    model.setMaterialTexture(2, game->getTexture("../assets/textures/models/tetra/pupil.png"));
    model.setMaterialTexture(3, game->getTexture("../assets/textures/models/tetra/eye1.png"));
    model.setMaterialTexture(4, game->getTexture("../assets/textures/models/tetra/pupil.png"));
    model.setMaterialTexture(5, game->getTexture("../assets/textures/models/tetra/eyebrow1.png"));
    model.setMaterialTexture(6, game->getTexture("../assets/textures/models/tetra/eyebrow1.png"));
    model.setMaterialTexture(7, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(8, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(9, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(10, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(11, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(12, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(13, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(14, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(15, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(16, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(17, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(18, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(19, game->getTexture("../assets/textures/models/tetra/mouth1.png"));
    model.setMaterialTexture(20, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.setMaterialTexture(21, game->getTexture("../assets/textures/models/tetra/body.png"));
    model.addAnimation("idle", idle);
    model.addAnimation("run", run);
    model.addAnimation("drop", drop);
    model.addAnimation("death", death);
    model.addAnimation("win", win);
    model.addAnimation("defeat", defeat);
    model.playAnimation("idle");
    _sounds["shield"] = "../assets/sounds/tetra/death.wav";
    _sounds["death"] = "../assets/sounds/tetra/shield.wav";
}