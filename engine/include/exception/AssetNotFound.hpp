/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** AssetNotFound
*/

#ifndef ASSETNOTFOUND_HPP_
#define ASSETNOTFOUND_HPP_

#include "exception/IndieException.hpp"

namespace indie
{
    class AssetNotFound : public IndieException {
        public:
            AssetNotFound(const std::string &type, const std::string &path) : IndieException(type + " PATH=" + path) {};
            ~AssetNotFound() = default;
    };
}

#endif /* !ASSETNOTFOUND_HPP_ */