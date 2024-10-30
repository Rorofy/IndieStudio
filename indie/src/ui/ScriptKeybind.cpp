/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** ScriptKeybind
*/

#include <iostream>
#include "ui/ScriptKeybind.hpp"
#include "irrlicht/event/KeyInput.hpp"
#include "irrlicht/Text.hpp"
#include "Settings.hpp"

using namespace game;

ScriptKeybind::ScriptKeybind(indie::Scene &scene, indie::Entity entity) :
    indie::AScript(scene, entity),
    _isActive(false)
{
    scene.getEventBus().subscribe<ScriptKeybind, ButtonClick>(*this, [this](ButtonClick &button) {
        this->onButtonClick(button);
    });
    scene.getEventBus().subscribe<ScriptKeybind, irl::KeyInput>(*this, [this](irl::KeyInput &input) {
        if (input.getInput().PressedDown) this->onKeyDown(input);
    });
}

ScriptKeybind::~ScriptKeybind()
{
}


void ScriptKeybind::onButtonClick(game::ButtonClick &button)
{
    if (button.getEntity() == _entity && button.getName() == "keybind") {
        auto &text = _scene.getComponent<irl::Text>(_entity);

        _value = button.getValue();
        _isActive = true;
        text.setString("...");
    }
}

void ScriptKeybind::onKeyDown(irl::KeyInput &input)
{
    if (_isActive) {
        auto &text = _scene.getComponent<irl::Text>(_entity);
        irr::core::stringw nw = L"";

        nw += input.getInput().Char;
        game::g_settings->setKey(_value, input.getInput().Char);
        text.setString(nw);
        _isActive = false;
    }
}

void ScriptKeybind::update(void)
{
}

void ScriptKeybind::render(void)
{
}