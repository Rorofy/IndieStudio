/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Scenes
*/

#ifndef SCENES_HPP_
#define SCENES_HPP_

#include "Game.hpp"

namespace game
{
    std::shared_ptr<indie::Scene> createSceneMenu(void);
    std::shared_ptr<indie::Scene> createSceneDevRoom(void);
    std::shared_ptr<indie::Scene> createSceneSettings(void);
    std::shared_ptr<indie::Scene> createSceneSettings2(void);
    std::shared_ptr<indie::Scene> createSceneSplash(void);
}

#endif /* !SCENES_HPP_ */
