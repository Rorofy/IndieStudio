/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MouseClick
*/

#ifndef MOUSECLICK_HPP_
#define MOUSECLICK_HPP_

#include "event/IEvent.hpp"

namespace irl
{
    class MouseClick : public indie::IEvent
    {
        public:
            MouseClick(int x, int y);
            ~MouseClick() = default;

            int getX() const;
            int getY() const;
        private:
            int _x;
            int _y;
    };
}

#endif /* !MOUSECLICK_HPP_ */
