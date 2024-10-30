/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "ecs/Scene.hpp"
#include "ecs/Entity.hpp"
#include "irrlicht.h"

namespace irl
{
    class Camera {
        public:
            Camera();
            ~Camera() = default;

            void init(indie::Scene &scene);
            void setEntityTarget(indie::Scene &scene, indie::Entity entity);
            void setPos(irr::core::vector3df &pos);
            void setRotation(irr::core::vector3df &pos);
            void setTarget(irr::core::vector3df &pos);
        private:
            bool _entityTarget;
            indie::Entity _entity;
            irr::scene::ICameraSceneNode *_camera;
    };
}

#endif /* !CAMERA_HPP_ */
