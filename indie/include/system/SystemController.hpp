/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemController
*/

#ifndef SYSTEMCONTROLLER_HPP_
#define SYSTEMCONTROLLER_HPP_

#include <unordered_map>
#include "ecs/ASystem.hpp"
#include "irrlicht/event/KeyInput.hpp"

namespace game
{
    class SystemController : public indie::ASystem {
        public:
            SystemController(indie::Scene &scene);
            ~SystemController() = default;

            void init(void) override;
            void update(void) override;
            void render(void) override;
            void handleStaticAction(irl::KeyInput &input);
            void onButtonPressed(irl::KeyInput &input);
        private:
            std::vector<wchar_t> _actives;
    };
}

#endif /* !SYSTEMCONTROLLER_HPP_ */
