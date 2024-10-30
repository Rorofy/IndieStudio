/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** SystemController
*/

#include <algorithm>
#include "system/SystemController.hpp"
#include "Game.hpp"
#include "component/Controller.hpp"
#include "Settings.hpp"

using namespace game;

SystemController::SystemController(indie::Scene &scene) :
    ASystem(scene)
{
}

void SystemController::init(void)
{
    _scene.getEventBus().subscribe<SystemController, irl::KeyInput>(*this, [this](irl::KeyInput &input) {
        this->onButtonPressed(input);
    });
    trackComponent<Controller>();
}

void SystemController::update(void)
{
    if (_actives.size() == 0) return;
    for (auto i : _entityRegistry) {
        Controller &controller = _scene.getComponent<Controller>(i);

        for (auto key : _actives) {
            auto name = game::g_settings->getKeyName(key);

            if (name == "") continue;
            if (controller.haveAction(name))
                controller.playAction(_scene, i, name);
        }
    }
}

void SystemController::render(void)
{
}

void SystemController::handleStaticAction(irl::KeyInput &input)
{
    auto name = game::g_settings->getKeyName(input.getInput().Char);

    for (auto i : _entityRegistry) {
        Controller &controller = _scene.getComponent<Controller>(i);

        controller.playSub(_scene, i, input);
        if (input.getInput().PressedDown || name == "") continue;
        controller.playStaticAction(_scene, i, name);
    }
}

void SystemController::onButtonPressed(irl::KeyInput &input)
{
    auto key = input.getInput();
    auto value = std::find(_actives.begin(), _actives.end(), key.Char);

    handleStaticAction(input);
    if (key.PressedDown) {
        if (value != _actives.end()) return;
        _actives.push_back(key.Char);
    }
    else {
        if (value == _actives.end()) return;
        _actives.erase(value);
    }
}