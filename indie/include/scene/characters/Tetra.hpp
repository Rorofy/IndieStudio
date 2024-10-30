/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Tetra
*/

#ifndef TETRA_HPP_
#define TETRA_HPP_

#include "scene/characters/ACharacter.hpp"

namespace game
{
    class Tetra : public ACharacter {
        public:
            Tetra() = default;
            ~Tetra() = default;

            void init(irl::Object3d &model) override;
    };
}

#endif /* !TETRA_HPP_ */
