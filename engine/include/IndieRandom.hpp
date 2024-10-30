/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** IndieRandom
*/

#ifndef INDIERANDOM_HPP_
#define INDIERANDOM_HPP_

#include <random>

namespace indie
{
    template<typename T>
    T random(T range_from, T range_to) {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(range_from, range_to);

        return distr(generator);
    }
}

#endif /* !INDIERANDOM_HPP_ */