/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** EntityRemove
*/

#ifndef ENTITYREMOVE_HPP_
#define ENTITYREMOVE_HPP_

#include "event/IEvent.hpp"
#include "ecs/Entity.hpp"

namespace indie
{
    class EntityRemove : public indie::IEvent
    {
        public:
            EntityRemove(Entity entity);
            ~EntityRemove() = default;

            [[nodiscard]] Entity getEntity() const;
        private:
            Entity _entity;
    };
}

#endif /* !ENTITYREMOVE_HPP_ */