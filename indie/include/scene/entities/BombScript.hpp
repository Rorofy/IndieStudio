/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** BombScript
*/

#ifndef BOMBSCRIPT_HPP_
#define BOMBSCRIPT_HPP_

#include "irrlicht.h"
#include "component/Script.hpp"
#include "Vector4.hpp"

namespace game
{
    class BombScript : public indie::AScript {
        public:
            BombScript(indie::Scene &scene, indie::Entity entity, int range);
            ~BombScript() = default;

            void update(void) override;
            void render(void) override;
            void explose(std::vector<std::vector<indie::Entity>> &map);
            int getRange(void) const;

        public:
            static const long BOMB_LIFESPAN;
        private:
            int _range;
            int exploseLine(std::vector<std::vector<indie::Entity>> &map,
                const irr::core::vector2di &offset);
            void exploseActors(std::vector<std::vector<indie::Entity>> &map,
                const Vector4<int> &range);
            long _counter;
    };
}

#endif /* !BOMBSCRIPT_HPP_ */
