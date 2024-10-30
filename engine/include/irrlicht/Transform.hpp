/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

namespace irl
{
    class Transform
    {
        public:
            Transform();
            ~Transform() = default;
            void setPos(float x, float y, float z);
            void setRot(float x, float y, float z);
            [[nodiscard]] const float getX() const;
            [[nodiscard]] const float getY() const;
            [[nodiscard]] const float getZ() const;
            [[nodiscard]] const float getRotX() const;
            [[nodiscard]] const float getRotY() const;
            [[nodiscard]] const float getRotZ() const;

        private:
            float _x;
            float _y;
            float _z;
            float _rotX;
            float _rotY;
            float _rotZ;
    };
}

#endif /* !TRANSFORM_HPP_ */