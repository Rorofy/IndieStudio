/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "ecs/Scene.hpp"

namespace game
{
    indie::Entity createBomb(indie::Scene &scene, const irr::core::vector3df &pos, int range);
}

#endif /* !BOMB_HPP_ */
