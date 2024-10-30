/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic [WSL]
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <cstddef>

namespace indie
{
    extern std::size_t g_lastId;

    template<typename T>
    class Component {
        public:
            Component() = default;
            ~Component() = default;

            static inline std::size_t getId() {
                static std::size_t _id = g_lastId++;

                return _id;
            }
    };
}

#endif /* !COMPONENT_HPP_ */