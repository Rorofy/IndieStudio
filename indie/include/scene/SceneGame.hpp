/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_

#include "ecs/Scene.hpp"

namespace game
{
    std::shared_ptr<indie::Scene> createSceneGame(void);
    std::shared_ptr<indie::Scene> createSceneFinal(int winnerType);
}

#endif /* !SCENEGAME_HPP_ */