/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MapConvert
*/

#include <iostream>
#include "Game.hpp"
#include "irrlicht/Sprite.hpp"
#include "irrlicht/Object3d.hpp"
#include "event/EventBus.hpp"
#include "scene/entities/Rock.hpp"
#include "scene/entities/Pot.hpp"
#include "scene/entities/Powerups.hpp"
#include "ui/SystemButton.hpp"
#include "system/SystemSprite.hpp"
#include "Position.hpp"
#include "Map.hpp"
#include "MapConvert.hpp"
#include "IndieRandom.hpp"

void mapConverter(indie::Scene &level, const std::vector<std::vector<char>> &map,
    std::vector<std::vector<indie::Entity>> &entities)
{
    irr::core::vector3df pos;
    irr::core::vector3df rigidSize = {1.5f, 0, 1.5f};
    int x = 0;
    int y = map.size() - 1;

    pos.Z = rigidSize.Z * y;
    pos.X = rigidSize.X * x;
    for (auto const &v : map) {
        for (auto const &e : v) {
            switch (e) {
                case WALL:
                    entities[y][x] = game::createRock(level, pos);
                    break;
                case BLOCK:
                    entities[y][x] = game::createPot(level, pos, 0);
                    break;
                case FASTBOOTS:
                    entities[y][x] = game::createPot(level, pos, FASTBOOTS);
                    break;
                case SLOWBOOTS:
                    entities[y][x] = game::createPot(level, pos, SLOWBOOTS);
                    break;
                case BIGBOMB:
                    entities[y][x] = game::createPot(level, pos, BIGBOMB);
                    break;
                case DOUBLEBOMB:
                    entities[y][x] = game::createPot(level, pos, DOUBLEBOMB);
                    break;
                case SHIELD:
                    entities[y][x] = game::createPot(level, pos, SHIELD);
                    break;
                default:
                    break;
            }
            x++;
            pos.X = rigidSize.X * x;
        }
        y--;
        x = 0;
        pos.Z = rigidSize.Z * y;
        pos.X = rigidSize.X * x;
    }
}
