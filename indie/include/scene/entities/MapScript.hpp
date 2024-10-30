/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MapScript
*/

#ifndef MAPSCRIPT_HPP_
#define MAPSCRIPT_HPP_

#include <memory>
#include "component/Script.hpp"

namespace game
{
    class MapScript : public indie::AScript {
        public:
            MapScript(indie::Scene &scene, indie::Entity entity, size_t width = 10, size_t height = 10);
            ~MapScript() = default;

            void update(void) override;
            void render(void) override;
            std::vector<std::vector<indie::Entity>> &getMap(void);
        private:
            void spawnCamera(size_t width, size_t height);
            void spawnPlayers(void);
            [[nodiscard]] irr::core::vector3df findPlayerSpawn(int type);

            std::vector<std::vector<indie::Entity>> _map;
    };
}

#endif /* !MAPSCRIPT_HPP_ */