/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Player
*/

#include "Game.hpp"
#include "scene/entities/Bomb.hpp"
#include "scene/entities/Player.hpp"
#include "component/Script.hpp"
#include "scene/entities/Player.hpp"
#include "scene/entities/BombScript.hpp"
#include "irrlicht/Object3d.hpp"
#include "scene/SceneGame.hpp"
#include "component/Controller.hpp"
#include "component/Actor.hpp"
#include "component/Lifespan.hpp"
#include "component/SoundFX.hpp"
#include "Settings.hpp"
#include "ui/Pause.hpp"
#include "Map.hpp"

using namespace game;

static void createActor(indie::Scene &scene, Actor &actor, int type)
{
    actor.setCallback(std::make_unique<PlayerDestroyCallback>(type));
    actor.setPowerup("shield", false);
    actor.setPowerup("bigbomb", false);
    actor.setPowerup("doublebomb", false);
    actor.setPowerup("speedboot", false);
    actor.setPowerup("slowboot", false);
}

static void move(indie::Scene &scene, indie::Entity player,
    const irr::core::vector3df &tr, const irr::core::vector3df &rot)
{
    irl::Object3d &obj = scene.getComponent<irl::Object3d>(player);
    game::Actor &actor = scene.getComponent<game::Actor>(player);
    float move = 1 + (actor.getPowerup("slowboot") ? -0.3f : 0) + (actor.getPowerup("speedboot") ? 0.3f : 0);

    obj.playAnimation("run");
    obj.setRotation(rot.X, rot.Y, rot.Z);
    obj.setPos(obj.getX() + (tr.X * move), obj.getY() + (tr.Y * move), obj.getZ() + (tr.Z * move));
}

static void createController(indie::Scene &scene, indie::Entity player, int type)
{
    Controller &controller = scene.addComponent<Controller>(player);
    indie::Entity pause = scene.spawnEntity();
    std::string typeN = std::to_string(type);

    controller.addAction("up"+typeN, {[](indie::Scene &scene, indie::Entity &player) {
        move(scene, player, {0, 0, 0.1f}, {0, 180, 0});
    }});
    controller.addAction("down"+typeN, {[](indie::Scene &scene, indie::Entity &player) {
        move(scene, player, {0, 0, -0.1f}, {0, 0, 0});
    }});
    controller.addAction("left"+typeN, {[](indie::Scene &scene, indie::Entity &player) {
        move(scene, player, {-0.1f, 0, 0}, {0, 90, 0});
    }});
    controller.addAction("right"+typeN, {[](indie::Scene &scene, indie::Entity &player) {
        move(scene, player, {0.1f, 0, 0}, {0, 270, 0});
    }});
    controller.addStaticAction("bomb"+typeN, {[](indie::Scene &scene, indie::Entity &player) {
        irl::Object3d &obj = scene.getComponent<irl::Object3d>(player);
        game::Controller &controller = scene.getComponent<game::Controller>(player);
        game::Actor &actor = scene.getComponent<game::Actor>(player);

        if (actor.getPowerup("doublebomb")) controller.changeStaticCooldown("bomb", game::BombScript::BOMB_LIFESPAN/2);
        obj.playAnimation("drop");
        game::createBomb(scene, {obj.getX(), obj.getY(), obj.getZ()}, actor.getPowerup("bigbomb") ? 2 : 1);
    }}, game::BombScript::BOMB_LIFESPAN);
    controller.addSub({[typeN](indie::Scene &scene, indie::Entity &entity, irl::KeyInput &input) {
        if (!input.getInput().PressedDown && (input.getInput().Char == game::g_settings->getKey("up"+typeN) ||
            input.getInput().Char == game::g_settings->getKey("down"+typeN) ||
            input.getInput().Char == game::g_settings->getKey("left"+typeN) ||
            input.getInput().Char == game::g_settings->getKey("right"+typeN))) {
                irl::Object3d &model = scene.getComponent<irl::Object3d>(entity);

                model.playAnimation("idle");
            }
    }});

}

indie::Entity game::createPlayer(indie::Scene &scene, std::shared_ptr<ACharacter> character,
    const irr::core::vector3df &pos, int type)
{
    indie::Entity player = scene.spawnEntity();
    irl::Object3d &obj = scene.addComponent<irl::Object3d>(player);
    auto &actor = scene.addComponent<game::Actor>(player);

    character->init(obj);
    actor.setCharacter(std::move(character));
    createController(scene, player, type);
    createActor(scene, actor, type);
    obj.setPos(pos);

    const core::aabbox3d<f32>& box = obj.get3dObject()->getBoundingBox();
    core::vector3df radius = box.MaxEdge - box.getCenter();

    auto anim = indie::getSceneManager().createCollisionResponseAnimator(indie::Game::g_instance->getSelector(),
        obj.get3dObject(), radius, core::vector3df(0,0,0),  core::vector3df(0,0,0), 0);
    obj.get3dObject()->addAnimator(anim);
    anim->drop();
    return player;
}

static void createSceneFinalCallback(indie::Scene &scene, int winnerType)
{
    indie::Entity timer = scene.spawnEntity();
    auto &lifespan = scene.addComponent<indie::Lifespan>(timer);
    auto &actors = scene.getEntityWith<Actor>();

    for (auto actor : actors) {
        scene.removeComponent<Controller>(actor.first);
        scene.removeComponent<Actor>(actor.first);
    }
    lifespan.setLifespan(4000);
    lifespan.setCallback({[winnerType](indie::Scene &scene, indie::Entity entity) {
        game::createSceneFinal(winnerType == 1 ? 2 : 1);
        indie::Game::g_instance->removeScene(scene);
    }});
}

bool PlayerDestroyCallback::destroy(indie::Scene &scene, indie::Entity entity)
{
    irl::Object3d &obj = scene.getComponent<irl::Object3d>(entity);
    auto &actor = scene.getComponent<game::Actor>(entity);

    if (actor.getPowerup("shield")) {
        actor.setPowerup("shield", false);
        indie::createSoundEntity(scene, actor.getCharacter().getSound("shield"), 1000);
    }
    else {
        obj.playAnimation("death");
        indie::createSoundEntity(scene, actor.getCharacter().getSound("death"), 1000);
        createSceneFinalCallback(scene, _type);
    }
    return false;
}