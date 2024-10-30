/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Camera
*/

#include "Game.hpp"
#include "irrlicht/Object3d.hpp"
#include "irrlicht/Camera.hpp"

using namespace irl;

Camera::Camera()
{
}

void Camera::init(indie::Scene &scene)
{
    _camera = indie::getSceneManager().addCameraSceneNode();
}

void Camera::setEntityTarget(indie::Scene &scene, indie::Entity entity)
{
    _entityTarget = true;
    _entity = entity;
    _camera->setParent(scene.getComponent<irl::Object3d>(entity).get3dObject());
}

void Camera::setPos(irr::core::vector3df &pos)
{
    _camera->setPosition(pos);
}

void Camera::setRotation(irr::core::vector3df &rotation)
{
    _camera->setRotation(rotation);
}

void Camera::setTarget(irr::core::vector3df &pos)
{
    _camera->setTarget(pos);
}