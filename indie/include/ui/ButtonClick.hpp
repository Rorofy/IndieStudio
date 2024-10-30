/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** ButtonClick
*/

#ifndef BUTTONCLICK_HPP_
#define BUTTONCLICK_HPP_

#include "event/IEvent.hpp"
#include "ecs/Entity.hpp"
#include <string>

namespace game
{
    class ButtonClick : public indie::IEvent
    {
        public:
            ButtonClick(indie::Entity entity, const std::string &name, const std::string &value);
            ~ButtonClick() = default;

            [[nodiscard]] indie::Entity getEntity() const;
            [[nodiscard]] const std::string &getName() const;
            [[nodiscard]] const std::string &getValue() const;
        private:
            indie::Entity _entity;
            std::string _name;
            std::string _value;
    };

}
#endif /* !BUTTONCLICK_HPP_ */
