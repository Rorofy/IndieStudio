/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Actor
*/

#ifndef ACTOR_HPP_
#define ACTOR_HPP_

#include "ecs/Scene.hpp"
#include "component/Destroyable.hpp"
#include "scene/characters/ACharacter.hpp"

namespace game 
{
    class Actor : public Destroyable
    {
        public:
            Actor() = default;
            Actor(int value);
            ~Actor() = default;

            void setPowerup(const std::string name, bool value);
            bool getPowerup(const std::string name) const;
            void setCharacter(std::shared_ptr<game::ACharacter> character) {
                _character = std::move(character);
            }

            const ACharacter &getCharacter(void) const {
                return *_character;
            }

        private:
            std::unordered_map<std::string, bool> _powerups;
            std::shared_ptr<game::ACharacter> _character;
    };
}

#endif /* !ACTOR_HPP_ */