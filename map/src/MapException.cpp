/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MapException
*/

#include "MapException.hpp"

MapException::MapException(std::string const &message, int const value) throw(): _errorMessage(message), _exitValue(value)
{

}

MapException::~MapException() throw()
{

}

std::string MapException::getMapException() const {
    return _errorMessage;
}

int MapException::getExitValue() const {
    return _exitValue;
}