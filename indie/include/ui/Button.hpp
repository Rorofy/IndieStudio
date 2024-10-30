/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <string>
#include <functional>
#include "ecs/Scene.hpp"

namespace game
{
    class Button {
        public:
            Button() = default;
            ~Button() = default;

            void setHitbox(int width, int height);
            void setHeight(int height);
            void setName(const std::string &name);
            void setValue(const std::string &value);
            void setOnClick(std::function<void (indie::Scene &, indie::Entity)> onClick);
            void setWidth(int width);
            [[nodiscard]] bool isClickable(void) const;
            [[nodiscard]] int getHeight(void) const;
            [[nodiscard]] int getWidth(void) const;
            [[nodiscard]] const std::string &getName(void) const;
            [[nodiscard]] const std::string &getValue(void) const;
            [[nodiscard]] const std::function<void (indie::Scene &, indie::Entity)> &getOnClick() const;

        private:
            std::string _name;
            std::string _value;
            int _width;
            int _height;
            bool _click;
            std::function<void (indie::Scene &, indie::Entity)> _onClick;
    };
}

#endif /* !BUTTON_HPP_ */
