/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_

namespace game
{
    class Position
    {
        public:
            Position() = default;
            ~Position() = default;
            void setPos(int x, int y, int z);
            [[nodiscard]] const int &getX() const;
            [[nodiscard]] const int &getY() const;
            [[nodiscard]] const int &getZ() const;

        private:
            int _x;
            int _y;
            int _z;
    };
}

#endif /* !POSITION_HPP_ */
