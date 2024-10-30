/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Pot
*/

#ifndef POT_HPP_
#define POT_HPP_

#include "ecs/Scene.hpp"
#include "component/Destroyable.hpp"

namespace game
{
    class PotDestroyCallback : public Destroyable::IDestroyCallback {
        public:
            PotDestroyCallback(int type) : _type(type) {};
            ~PotDestroyCallback() = default;

            bool destroy(indie::Scene &scene, indie::Entity) override;
            void spawnPowerup(indie::Scene &scene, const vector3df &pos);
            void spawnParticle(indie::Scene &scene, const vector3df &pos);
        private:
            int _type = 0;
    };
    indie::Entity createPot(indie::Scene &scene, irr::core::vector3df pos, int type);
}

#endif /* !POT_HPP_ */