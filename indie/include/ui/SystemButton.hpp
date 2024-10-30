/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemButton
*/

#ifndef SYSTEMBUTTON_HPP_
#define SYSTEMBUTTON_HPP_

#include "ui/Button.hpp"
#include "Position.hpp"
#include "irrlicht/event/MouseClick.hpp"

namespace game
{
    class SystemButton : public indie::ASystem
    {
        public:
            SystemButton(indie::Scene &scene);
            ~SystemButton();

            void onMouseClick(irl::MouseClick &evt);
            void init() override;
            void update() override;
            void render() override;
    };
}

#endif /* !SYSTEMBUTTON_HPP_ */
