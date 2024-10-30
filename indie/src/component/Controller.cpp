/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Controller
*/

#include <iostream>
#include "component/Controller.hpp"

using namespace game;

void Controller::addAction(const std::string &name, controllerAction action)
{
    _actions[name] = action;
    _actionSub[name] = true;
}

void Controller::addSub(subAction action)
{
    _subs.push_back(action);
}

void Controller::addStaticAction(const std::string &name, controllerAction action, std::size_t cooldown)
{
    StaticAction stac {action, cooldown};

    _staticActions[name] = stac;
}

bool Controller::haveAction(const std::string &name)
{
    return _actionSub[name];
}

void Controller::playAction(indie::Scene &scene, indie::Entity entity, const std::string &name) const
{
    try {
        _actions.at(name)(scene, entity);
    } catch (std::exception &e) {
    }
}

void Controller::playSub(indie::Scene &scene, indie::Entity entity, irl::KeyInput &input)
{
    for (auto &i : _subs) i(scene, entity, input);
}


void Controller::playStaticAction(indie::Scene &scene, indie::Entity entity, const std::string &name)
{
    try {
        auto &action = _staticActions[name];

        if (action.canPlayAction()) {
            action.getAction()(scene, entity);
            action.resetCooldown();
        }
    } catch (std::exception &e) {
    }
}

void Controller::changeStaticCooldown(const std::string &name, std::size_t cooldown)
{
    _staticActions[name].setCooldown(cooldown);
}

Controller::StaticAction::StaticAction(controllerAction &action, std::size_t cooldown) :
    _action(action),
    _cooldown(cooldown),
    _timer(0)
{
    _clock = std::chrono::high_resolution_clock::now();
}

controllerAction &Controller::StaticAction::getAction(void)
{
    return _action;
}

bool Controller::StaticAction::canPlayAction(void)
{
    auto now = std::chrono::high_resolution_clock::now();
    long elaps = std::chrono::duration_cast<std::chrono::milliseconds>((now - _clock)).count();

    if (elaps >= _timer) {
        _timer = 0;
        return true;
    }
    _timer -= elaps;
    _clock = now;
    return false;
}

void Controller::StaticAction::resetCooldown(void)
{
    _clock = std::chrono::high_resolution_clock::now();
    _timer = _cooldown;
}

void Controller::StaticAction::setCooldown(std::size_t cooldown)
{
    _cooldown = cooldown;
}