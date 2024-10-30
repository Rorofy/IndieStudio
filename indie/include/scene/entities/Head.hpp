/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Head
*/

#ifndef HEAD_HPP_
#define HEAD_HPP_

#include "ecs/Scene.hpp"

namespace game
{
    indie::Entity createHead(indie::Scene &scene, irr::core::vector3df pos = {0, 0, 0});
}

#endif /* !HEAD_HPP_ */