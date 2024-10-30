/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** IndieModel
*/

#include "Game.hpp"
#include "irrlicht/Object3d.hpp"
#include "exception/AssetNotFound.hpp"

using namespace irl;

Object3dImpl::Object3dImpl() :
    _mesh(NULL),
    _3dObject(NULL)
{
}

Object3dImpl::~Object3dImpl()
{
    if (_3dObject != NULL) {
        auto selector = _3dObject->getTriangleSelector();
        auto animators = _3dObject->getAnimators();

        if (selector != NULL) {
            indie::Game::g_instance->getSelector()->removeTriangleSelector(selector);
            _3dObject->setTriangleSelector(NULL);
        }
        _3dObject->removeAnimators();
        _3dObject->remove();
        _3dObject = NULL;
    }
}

void Object3dImpl::setMesh(const std::string &path)
{
    ISceneManager &scn = indie::getSceneManager();

    _mesh = scn.getMesh(path.c_str());
    if (_mesh == NULL)
        throw indie::AssetNotFound("Model", path);
    _3dObject = scn.addAnimatedMeshSceneNode(_mesh);
    _3dObject->setCurrentFrame(0);
    _defaultSpeed = _3dObject->getAnimationSpeed();
}

void Object3dImpl::setMaterialTexture(u32 layer, ITexture *texture)
{
    _3dObject->getMaterial(layer).setTexture(0, texture);
}

void Object3dImpl::setMaterialType(u32 material, E_MATERIAL_TYPE type)
{
    _3dObject->getMaterial(material).MaterialType = type;
}

void Object3dImpl::setPos(const vector3df &pos)
{
    _3dObject->setPosition(pos);
}

void Object3dImpl::setPos(float x, float y, float z)
{
    vector3df pos = {x, y, z};

    _3dObject->setPosition(pos);
}

void Object3dImpl::setRotation(vector3df &rotation)
{
    _3dObject->setRotation(rotation);
}

void Object3dImpl::setRotation(float x, float y, float z)
{
    vector3df pos = {x, y, z};

    _3dObject->setRotation(pos);
}

IAnimatedMeshSceneNode *Object3dImpl::get3dObject(void) const
{
    return _3dObject;
}

vector3df Object3dImpl::getPos() const
{
    return _3dObject->getPosition();
}

float Object3dImpl::getX(void) const
{
    return _3dObject->getPosition().X;
}

float Object3dImpl::getY(void) const
{
    return _3dObject->getPosition().Y;
}

float Object3dImpl::getZ(void) const
{
    return _3dObject->getPosition().Z;
}

void Object3dImpl::playAnimation(const std::string &name)
{
    if (_name == name) return;
    Animation &anim = _anims[name];

    _name = name;
    _3dObject->setAnimationSpeed(anim.getSpeed() != 0 ? anim.getSpeed() : _defaultSpeed);
    if (anim.isLooped()) {
        _3dObject->setLoopMode(true);
        _3dObject->setFrameLoop(anim.getStart(), anim.getEnd());
    }
    else {
        _3dObject->setLoopMode(false);
        _3dObject->setCurrentFrame(anim.getStart());
        _3dObject->setFrameLoop(anim.getStart(), anim.getEnd());
        _3dObject->setAnimationEndCallback(new Object3d::Animation::Object3dAnimationCallback());
    }
}

void Object3dImpl::addAnimation(const std::string &name, Animation &anim)
{
    _anims[name] = anim;
}

void Object3dImpl::clear(void)
{
    _3dObject = NULL;
}

Object3d &Object3d::operator=(Object3d &model)
{
    if (_3dObject != NULL) {
        auto selector = _3dObject->getTriangleSelector();

        if (selector != NULL) {
            indie::Game::g_instance->getSelector()->removeTriangleSelector(selector);
            _3dObject->setTriangleSelector(NULL);
        }
        _3dObject->removeAnimators();
        _3dObject->remove();
        _3dObject = NULL;
    }
    Object3dImpl::operator=(model);
    model.clear();
    return *this;
}

Object3d::Animation::Animation(int start) :
    _start(start),
    _end(0),
    _loop(false)
{
}

Object3d::Animation::Animation(int start, int end, bool loop, f32 speed) :
    _start(start),
    _end(end),
    _loop(loop),
    _speed(speed)
{
}

int Object3d::Animation::getStart(void) const
{
    return _start;
}

int Object3d::Animation::getEnd(void) const
{
    return _end;
}

bool Object3d::Animation::isLooped(void) const
{
    return _loop;
}

f32 Object3d::Animation::getSpeed(void) const
{
    return _speed;
}

void Object3d::Animation::Object3dAnimationCallback::OnAnimationEnd(IAnimatedMeshSceneNode* node)
{
    node->setAnimationSpeed(0);
}