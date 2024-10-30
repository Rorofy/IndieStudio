/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** EventReceiver
*/

#ifndef EVENTRECEIVER_HPP_
#define EVENTRECEIVER_HPP_

#include <irrlicht.h>

using namespace irr;

namespace irl
{
    class EventReceiver : public  IEventReceiver {
        public:
            EventReceiver() = default;
            ~EventReceiver() = default;

            virtual bool OnEvent(const SEvent &event) override;
    };
}

#endif /* !EVENTRECEIVER_HPP_ */