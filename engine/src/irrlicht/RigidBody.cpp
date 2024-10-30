/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** RigidBody
*/

#include "Game.hpp"
#include "irrlicht/RigidBody.hpp"

using namespace irl;

void RigidBody::init(irl::Object3d &model)
{
    auto &scene = indie::getSceneManager();
    auto object = model.get3dObject();

    _selector = scene.createTriangleSelectorFromBoundingBox(object);
    object->setTriangleSelector(_selector);
    indie::Game::g_instance->getSelector()->addTriangleSelector(_selector);
    _selector->drop();
}

void RigidBody::setSize(int x, int y, int z) 
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

const int &RigidBody::getX() const
{
    return this->_x; 
}

const int &RigidBody::getY() const 
{
    return this->_y; 
}

const int &RigidBody::getZ() const
{
    return this->_z; 
}

irr::scene::ITriangleSelector *RigidBody::getSelector(void)
{
    return _selector;
}