/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "ecs/Scene.hpp"
#include "component/Actor.hpp"
#include "scene/characters/ACharacter.hpp"

namespace game
{
    class PlayerDestroyCallback : public Actor::IDestroyCallback {
        public:
            PlayerDestroyCallback(int type) : _type(type) {};
            ~PlayerDestroyCallback() = default;

            bool destroy(indie::Scene &scene, indie::Entity) override;
        private:
            int _type;
    };
    indie::Entity createPlayer(indie::Scene &scene, std::shared_ptr<ACharacter> character,
        const irr::core::vector3df &pos, int player);
}

#endif /* !PLAYER_HPP_ */