/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** KeyInput
*/

#include "irrlicht/event/KeyInput.hpp"

using namespace irl;

KeyInput::KeyInput(const irr::SEvent::SKeyInput &input) :
    _input(input)
{
}

const irr::SEvent::SKeyInput &KeyInput::getInput() const
{
    return _input;
}