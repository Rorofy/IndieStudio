/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** ACharacter
*/

#ifndef ACHARACTER_HPP_
#define ACHARACTER_HPP_

#include <unordered_map>
#include "irrlicht/Object3d.hpp"

namespace game
{
    class ACharacter {
        public:
            virtual ~ACharacter() = default;

            virtual void init(irl::Object3d &model) = 0;

            const std::string &getSound(const std::string &name) const {
                return _sounds.at(name);
            }
        protected:
            std::unordered_map<std::string, std::string> _sounds;
    };
}

#endif /* !ACHARACTER_HPP_ */
