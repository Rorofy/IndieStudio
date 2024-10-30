/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Link
*/

#ifndef LINK_HPP_
#define LINK_HPP_

#include "scene/characters/ACharacter.hpp"

namespace game
{
    class Link : public ACharacter {
        public:
            Link() = default;
            ~Link() = default;

            void init(irl::Object3d &model) override;
    };
}

#endif /* !LINK_HPP_ */
