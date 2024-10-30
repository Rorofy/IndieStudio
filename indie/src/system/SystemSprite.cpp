/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemSprite
*/

#include "system/SystemSprite.hpp"
#include "irrlicht/Sprite.hpp"

using namespace game;

SystemSprite::SystemSprite(indie::Scene &scene) :
    ASystem(scene)
{
}

void SystemSprite::init()
{
    trackComponent<irl::Sprite>();
    trackComponent<game::Position>();
}

void SystemSprite::update()
{
}

void SystemSprite::render()
{
    for (auto &i : _entityRegistry) {
        game::Position &pos = _scene.getComponent<game::Position>(i);
        irl::Sprite &sprite = _scene.getComponent<irl::Sprite>(i);

        _scene.getComponent<irl::Sprite>(i).displaySprite(pos.getX(), pos.getY(), sprite.getOpacity());
    }
}