/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** EventReceiver
*/

#include "Game.hpp"
#include "irrlicht/event/EventReceiver.hpp"
#include "irrlicht/event/MouseClick.hpp"
#include "irrlicht/event/KeyInput.hpp"

using namespace irl;

bool EventReceiver::OnEvent(const SEvent &event)
{
    if (event.EventType == EET_MOUSE_INPUT_EVENT &&
        event.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN) {
        MouseClick click(event.MouseInput.X, event.MouseInput.Y);

        for (auto &i : indie::Game::g_instance->getScenes())
            i->getEventBus().publish<irl::MouseClick>(click);
    }
    if (event.EventType == EET_KEY_INPUT_EVENT) {
        KeyInput input(event.KeyInput);

        for (auto &i : indie::Game::g_instance->getScenes())
            i->getEventBus().publish<irl::KeyInput>(input);
    }
    return false;
}