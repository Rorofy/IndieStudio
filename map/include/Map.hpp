/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include <string>

#define WALL '*'
#define BLOCK 'o'
#define SPACE ' '
#define SLOWBOOTS 'b'
#define FASTBOOTS 'B'
#define BIGBOMB 'G'
#define SHIELD 'S'
#define DOUBLEBOMB 'D'

class Map {
    public:
        Map();
        explicit Map(int Width, int Height);
        ~Map() = default;

        // Map generation
        void mapGenerator();

        // Get
        [[nodiscard]] const std::vector<std::vector<char>> &getMap() const;
        [[nodiscard]] int getWidth() const;
        [[nodiscard]] int getHeight() const;

        // Misc
        void printMap();
    private:
        // Map generation
        void placeWall();
        void mapRand();
        void takeTheL();
        void powerUp();

        std::vector<std::vector<char>> _map;
        int _width;
        int _height;
};

#endif /* !MAP_HPP_ */
