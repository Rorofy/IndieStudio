/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Link
*/

#include "scene/characters/Link.hpp"
#include "Game.hpp"

using namespace game;

void Link::init(irl::Object3d &model)
{
    auto &game = indie::Game::g_instance;
    irl::Object3d::Animation idle(0, 88);
    irl::Object3d::Animation run(187, 213);
    irl::Object3d::Animation drop(215, 296, false, 180);
    irl::Object3d::Animation death(298, 362, false);
    irl::Object3d::Animation win(565, 1153);
    irl::Object3d::Animation defeat(365, 564);

    model.setMesh("../assets/models/link.b3d");
    model.setMaterialTexture(0, game->getTexture("../assets/textures/models/link/body.png"));
    model.setMaterialTexture(1, game->getTexture("../assets/textures/models/link/eye1.png"));
    model.setMaterialTexture(2, game->getTexture("../assets/textures/models/link/pupil.png"));
    model.setMaterialTexture(3, game->getTexture("../assets/textures/models/link/eye1.png"));
    model.setMaterialTexture(4, game->getTexture("../assets/textures/models/link/pupil.png"));
    model.setMaterialTexture(5, game->getTexture("../assets/textures/models/link/eyebrow1.png"));
    model.setMaterialTexture(6, game->getTexture("../assets/textures/models/link/eyebrow1.png"));
    model.setMaterialTexture(7, game->getTexture("../assets/textures/models/link/mouth1.png"));
    model.setMaterialTexture(8, game->getTexture("../assets/textures/models/link/sheath.png"));
    model.addAnimation("idle", idle);
    model.addAnimation("run", run);
    model.addAnimation("drop", drop);
    model.addAnimation("death", death);
    model.addAnimation("win", win);
    model.addAnimation("defeat", defeat);
    model.playAnimation("idle");
    _sounds["death"] = "../assets/sounds/link/death.wav";
    _sounds["shield"] = "../assets/sounds/link/shield.wav";
}