/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Powerups
*/

#ifndef POWERUPS_HPP_
#define POWERUPS_HPP_

#include "ecs/Scene.hpp"

namespace game
{
    indie::Entity createShield(indie::Scene &scene, const irr::core::vector3df &pos);
    indie::Entity createBigBomb(indie::Scene &scene, const irr::core::vector3df &pos);
    indie::Entity createDoubleBomb(indie::Scene &scene, const irr::core::vector3df &pos);
    indie::Entity createSlowBoot(indie::Scene &scene, const irr::core::vector3df &pos);
    indie::Entity createSpeedBoot(indie::Scene &scene, const irr::core::vector3df &pos);
}

#endif /* !POWERUPS_HPP_ */