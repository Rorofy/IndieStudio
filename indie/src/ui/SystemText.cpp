/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemButton
*/

#include "irrlicht/Text.hpp"
#include "ui/SystemText.hpp"
#include "ecs/Scene.hpp"
#include "Position.hpp"

using namespace game;

SystemText::SystemText(indie::Scene &scene) :
    ASystem(scene)
{
}

void SystemText::init()
{
    trackComponent<Position>();
    trackComponent<irl::Text>();
}

void SystemText::update()
{
}

void SystemText::render()
{
    for (auto i : _entityRegistry) {
        Position &pos = _scene.getComponent<Position>(i);
        irl::Text &text = _scene.getComponent<irl::Text>(i);
        rect<s32> rec(pos.getX(), pos.getY(), 0, 0);

        text.renderText(rec);
    }
}