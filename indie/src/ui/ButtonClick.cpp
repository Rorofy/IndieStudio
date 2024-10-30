/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** ButtonClick
*/

#include "ui/ButtonClick.hpp"

using namespace game;

ButtonClick::ButtonClick(indie::Entity entity, const std::string &name, const std::string &value) :
    _entity(entity),
    _name(name),
    _value(value)
{
}

indie::Entity ButtonClick::getEntity() const 
{
    return this->_entity;
}

const std::string &ButtonClick::getName() const 
{
    return this->_name;
}

const std::string &ButtonClick::getValue() const 
{
    return this->_value;
}