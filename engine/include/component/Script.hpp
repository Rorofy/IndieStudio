/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Script
*/

#ifndef SCRIPT_HPP_
#define SCRIPT_HPP_

#include "ecs/Scene.hpp"

namespace indie
{
    class AScript 
    {
        public:
            AScript() = default;
            AScript(indie::Scene &scene, indie::Entity entity);

            virtual ~AScript() = default;
            virtual void update(void) = 0;
            virtual void render(void) = 0;
        protected:
            indie::Scene &_scene;
            indie::Entity _entity;
    };

    class Script
    {
        public:
            Script() = default;
            ~Script() = default;

            void setScript(std::unique_ptr<AScript> script);
            AScript &getScript(void);

        private:
            std::shared_ptr<AScript> _script;
    };
}

#endif /* !SCRIPT_HPP_ */
