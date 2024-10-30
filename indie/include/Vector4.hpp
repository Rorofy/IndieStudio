/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Vector4
*/

#ifndef VECTOR4_HPP_
#define VECTOR4_HPP_

template<typename T>
class Vector4 {
    public:
        Vector4() = default;
        ~Vector4() = default;

        T _minX;
        T _maxX;
        T _minY;
        T _maxY;
};

#endif /* !VECTOR4_HPP_ */