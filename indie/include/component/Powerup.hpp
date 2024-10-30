/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Powerup
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "ecs/Scene.hpp"
#include "component/Destroyable.hpp"

namespace game 
{
    class Powerup
    {
        public:
            Powerup() = default;
            ~Powerup() = default;

            void setName(const std::string &name)
            {
                _name = name;
            }

            const std::string &getName(void) const
            {
                return _name;
            }

        private:
            std::string _name;
    };
}

#endif /* !POWERUP_HPP_ */