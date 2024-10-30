/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemSprite
*/

#ifndef SYSTEMSPRITE_HPP_
#define SYSTEMSPRITE_HPP_

#include "Position.hpp"
#include "ecs/Scene.hpp"

namespace game
{
    class SystemSprite : public indie::ASystem {
        public:
            SystemSprite(indie::Scene &scene);
            ~SystemSprite() = default;

            void init(void) override;
            void update(void) override;
            void render(void) override;
    };
}

#endif /* !SYSTEMSPRITE_HPP_ */
