/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemButton
*/

#include "ui/SystemButton.hpp"
#include "ui/ButtonClick.hpp"

using namespace game;

SystemButton::SystemButton(indie::Scene &scene) :
    ASystem(scene)
{
}

SystemButton::~SystemButton()
{
    /* To fix
    scene->getEventBus().unsubscribe<SystemButton, MouseClick>(*this); */
}

void SystemButton::onMouseClick(irl::MouseClick &evt) {
    for (auto i : _entityRegistry) {
        Position &pos = _scene.getComponent<Position>(i);
        Button &button = _scene.getComponent<Button>(i);

        if (evt.getX() >= pos.getX() && evt.getX() < (pos.getX() + button.getWidth()) &&
            evt.getY() >= pos.getY() && evt.getY() < (pos.getY() + button.getHeight())) {
                game::ButtonClick click(i, button.getName(), button.getValue());

                if (button.isClickable()) button.getOnClick()(_scene, i);
                _scene.getEventBus().publish<ButtonClick>(click);
            }

    }
}

void SystemButton::init()
{
    trackComponent<Position>();
    trackComponent<Button>();
    _scene.getEventBus().subscribe<SystemButton, irl::MouseClick>(*this, [this](irl::MouseClick &click) {
        this->onMouseClick(click);
    });
}

void SystemButton::update()
{
}

void SystemButton::render()
{
}