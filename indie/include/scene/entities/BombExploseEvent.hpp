/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** BombExploseEvent
*/

#ifndef BOMBEXPLOSEEVENT_HPP_
#define BOMBEXPLOSEEVENT_HPP_

#include "event/IEvent.hpp"
#include "ecs/Entity.hpp"
#include "scene/entities/BombScript.hpp"

namespace game
{
    class BombExploseEvent : public indie::IEvent
    {
        public:
            BombExploseEvent(BombScript &bomb) : _bomb(bomb) {}
            ~BombExploseEvent() = default;

            [[nodiscard]] BombScript &getBomb() const
            {
                return _bomb;
            }
        private:
            BombScript &_bomb;
    };
}

#endif /* !BOMBEXPLOSEEVENT_HPP_ */