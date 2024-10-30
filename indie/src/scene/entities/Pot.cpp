/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Rock
*/

#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>
#include "Game.hpp"
#include "scene/entities/Pot.hpp"
#include "irrlicht/Object3d.hpp"
#include "irrlicht/Transform.hpp"
#include "component/SoundFX.hpp"
#include "component/Lifespan.hpp"
#include "irrlicht/ParticleFX.hpp"
#include "irrlicht/RigidBody.hpp"
#include "component/Destroyable.hpp"
#include "IndieRandom.hpp"
#include "scene/entities/Powerups.hpp"
#include "Map.hpp"

using namespace game;

indie::Entity game::createPot(indie::Scene &scene, vector3df pos, int type)
{
    indie::Entity pot = scene.spawnEntity();
    irl::Object3d &obj = scene.addComponent<irl::Object3d>(pot);
    irl::RigidBody &rigid = scene.addComponent<irl::RigidBody>(pot);
    auto &destroy = scene.addComponent<game::Destroyable>(pot);

    destroy.setCallback(std::make_unique<PotDestroyCallback>(type));
    obj.setMesh("../assets/models/pot.b3d");
    obj.setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/map/PotLight.0.png"));
    obj.setPos(pos.X, pos.Y, pos.Z);
    rigid.init(obj);
    return pot;
}

void game::PotDestroyCallback::spawnPowerup(indie::Scene &scene, const vector3df &pos)
{
    switch (_type) {
        case FASTBOOTS:
            game::createSpeedBoot(scene, pos);
            break;
        case SLOWBOOTS:
            game::createSlowBoot(scene, pos);
            break;
        case BIGBOMB:
            game::createBigBomb(scene, pos);
            break;
        case DOUBLEBOMB:
            game::createDoubleBomb(scene, pos);
            break;
        case SHIELD:
            game::createShield(scene, pos);
            break;
        default:
            break;
    }
}

void game::PotDestroyCallback::spawnParticle(indie::Scene &scene, const vector3df &pos)
{
    indie::Entity part = scene.spawnEntity();
    auto &particle = scene.addComponent<irl::ParticleFX>(part);
    auto &lifespan = scene.addComponent<indie::Lifespan>(part);
    scene::IParticleSystemSceneNode *ps =
        indie::getSceneManager().addParticleSystemSceneNode(false);

    scene::IParticleEmitter *em = ps->createBoxEmitter(
        core::aabbox3d<f32>(pos.X, pos.Y,pos.Z, pos.X+1,pos.Y+0.3,pos.Z+1),
        core::vector3df(0.001f,0.009f,0.003f),
        200,200,
        video::SColor(0,255,255,255),
        video::SColor(0,255,255,255),
        10000,10000,270,
        core::dimension2df(0.1f,0.1f),
        core::dimension2df(0.1f,0.1f));
    ps->setEmitter(em);
    em->drop();
    scene::IParticleAffector *paf = ps->createGravityAffector();
    ps->addAffector(paf);
    paf->drop();
    ps->setMaterialFlag(video::EMF_LIGHTING, false);
    ps->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
    ps->setMaterialTexture(0, indie::Game::g_instance->getTexture("../assets/textures/models/map/pot_particle.png"));
    indie::createSoundEntity(scene, "../assets/sounds/pot.wav", 2000);
    particle.setSystem(ps);
    lifespan.setLifespan(300);
}

bool game::PotDestroyCallback::destroy(indie::Scene &scene, indie::Entity entity)
{
    auto &pos = scene.getComponent<irl::Object3d>(entity);

    spawnParticle(scene, pos.getPos());
    spawnPowerup(scene, pos.getPos());
    return true;
}