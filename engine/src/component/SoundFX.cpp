/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SoundFX
*/

#include "component/SoundFX.hpp"
#include "component/Lifespan.hpp"

using namespace indie;

Entity indie::createSoundEntity(Scene &scene, const std::string &path, long lifespan, bool looped)
{
    Entity entity = scene.spawnEntity();
    auto &comp = scene.addComponent<Lifespan>(entity);
    auto &sound = scene.addComponent<SoundFX>(entity);

    sound.setSound(path);
    if (looped) sound.getSound()->setLoop(true);
    sound.getSound()->play();
    comp.setLifespan(lifespan);
    return entity;
}

Entity indie::createSoundEntityCallback(Scene &scene, const std::string &path, long lifespan,
    const std::function<void (indie::Scene &, indie::Entity)> &callback, bool looped)
{
    Entity entity = scene.spawnEntity();
    auto &comp = scene.addComponent<Lifespan>(entity);
    auto &sound = scene.addComponent<SoundFX>(entity);

    sound.setSound(path);
    sound.getSound()->play();
    comp.setLifespan(lifespan);
    comp.setCallback(callback);
    return entity;
}