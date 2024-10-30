/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MapConvert
*/

#ifndef MAPCONVERT_HPP_
#define MAPCONVERT_HPP_

#include <iostream>
#include <string>
#include "irrlicht.h"

typedef struct rigidSize
{
    bool check;
    irr::core::vector3df size;
} rigidSize_t;

void mapConverter(indie::Scene &level, const std::vector<std::vector<char>> &map,
    std::vector<std::vector<indie::Entity>> &entities);

#endif /* !MAPCONVERT_HPP_ */
