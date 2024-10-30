/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** KeyInput
*/

#ifndef KEYINPUT_HPP_
#define KEYINPUT_HPP_

#include "IEventReceiver.h"
#include "event/IEvent.hpp"

namespace irl
{
    class KeyInput : public indie::IEvent {
        public:
            KeyInput(const irr::SEvent::SKeyInput &input);
            ~KeyInput() = default;

            const irr::SEvent::SKeyInput &getInput() const;
        private:
            const irr::SEvent::SKeyInput &_input;
    };
}

#endif /* !KEYINPUT_HPP_ */