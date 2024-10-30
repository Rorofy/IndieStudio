/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemText
*/

#ifndef SYSTEMTEXT_HPP_
#define SYSTEMTEXT_HPP_

#include "ecs/ASystem.hpp"

namespace game
{
    class SystemText : public indie::ASystem
    {
        public:
            SystemText(indie::Scene &scene);
            ~SystemText() = default;

            void init() override;
            void update() override;
            void render() override;
    };
}

#endif /* !SYSTEMTEXT_HPP_ */