/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemScript
*/

#ifndef SYSTEMSCRIPT_HPP_
#define SYSTEMSCRIPT_HPP_


#include "ecs/ASystem.hpp"

namespace indie
{
    class SystemScript : public indie::ASystem {
        public:
            SystemScript(Scene &scene);
            ~SystemScript() = default;

            void init() override;
            void update() override;
            void render() override;
    };
}

#endif /* !SYSTEMSCRIPT_HPP_ */