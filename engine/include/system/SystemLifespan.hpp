/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemLifespan
*/

#ifndef SYSTEMLIFESPAN_HPP_
#define SYSTEMLIFESPAN_HPP_

#include "ecs/ASystem.hpp"

namespace indie
{
    class SystemLifespan : public indie::ASystem {
        public:
            SystemLifespan(Scene &scene);
            ~SystemLifespan() = default;

            void init() override;
            void update() override;
            void render() override;
    };
}

#endif /* !SYSTEMLIFESPAN_HPP_ */