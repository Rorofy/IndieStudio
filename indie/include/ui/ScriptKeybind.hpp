/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** ScriptSetting
*/

#ifndef SCRIPTKEYBIND_HPP_
#define SCRIPTKEYBIND_HPP_

#include "component/Script.hpp"
#include "ui/ButtonClick.hpp"

namespace game
{
    class ScriptKeybind : public indie::AScript
    {
        public:
            ScriptKeybind(indie::Scene &scene, indie::Entity entity);
            ~ScriptKeybind();

            void update(void) override;
            void render(void) override;
            void onButtonClick(game::ButtonClick &button);
            void onKeyDown(irl::KeyInput &input);
        private:
            bool _isActive;
            std::string _value;
    };
}

#endif /* !SCRIPTKEYBIND_HPP_ */
