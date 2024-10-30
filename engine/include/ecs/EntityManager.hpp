/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <memory>
#include "ecs/Entity.hpp"

namespace indie
{
    class EntityManager {
        public:
            EntityManager();
            ~EntityManager();

            [[nodiscard]] Entity spawnEntity(void);
        private:
            std::size_t _lastId;
    };
}

#endif /* !ENTITYMANAGER_HPP_ */