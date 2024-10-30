/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Rock
*/

#ifndef ROCK_HPP_
#define ROCK_HPP_

#include "ecs/Scene.hpp"

namespace game
{
    indie::Entity createRock(indie::Scene &scene, irr::core::vector3df pos = {0, 0, 0});
    indie::Entity createRock2(indie::Scene &scene, irr::core::vector3df pos = {0, 0, 0});
}

#endif /* !ROCK_HPP_ */