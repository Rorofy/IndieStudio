/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemPowerup
*/

#ifndef SYSTEMPOWERUP_HPP_
#define SYSTEMPOWERUP_HPP_

#include "ecs/ASystem.hpp"
#include "irrlicht/Object3d.hpp"

namespace game
{
    class SystemPowerup : public indie::ASystem {
        public:
            SystemPowerup(indie::Scene &scene);
            ~SystemPowerup() = default;

            void init(void) override;
            void update(void) override;
            void render(void) override;

        private:
            void handleActor(indie::Entity powerup, indie::Entity actor);
            bool doActorCollide(const irl::Object3d &powerup,
                const irl::Object3d &actor);
    };
}

#endif /* !SYSTEMPOWERUP_HPP_ */