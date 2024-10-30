/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Map
*/

#include "Map.hpp"
#include "MapException.hpp"
#include <algorithm>
#include <iostream>
#include <random>

Map::Map() : _width(21), _height(21), _map(21)
{
    mapGenerator();
}

Map::Map(int Width, int Height = 21) : _width(Width), _height(Height), _map(Height)
{
    if (!(Width % 2))
        _width += 1;
    if (!(Height % 2))
        _height += 1;
    mapGenerator();
}

void Map::placeWall()
{
    if (_map.empty())
        throw(MapException("Error: Map is empty", 84));
    for (int h = 0; h < _height - 2 ; h++) {
        if (h % 2)
            continue;
        for (int w = 1; w < _width - 1; w++)
            if (!(w % 2))
                _map[h][w] = WALL;
    }
}

void Map::mapGenerator()
{
    std::vector<char>buf(_width);
    std::vector<char>center;

    if (!_map.empty())
        _map.clear();
    std::fill(buf.begin(), buf.begin() + _width, WALL);
    center = buf;
    std::fill(center.begin() + 1, center.begin() + _width - 1, BLOCK);
    for (int h = 0; h < _height; h++)
        if (!h || h + 1 == _height)
            _map.push_back(buf);
        else
            _map.push_back(center);
    placeWall();
    takeTheL();
    mapRand();
    powerUp();
}

void Map::printMap()
{
    for (std::vector<std::vector<char>>::iterator it = _map.begin(); it != _map.end(); ++it) {
        for (std::vector<char>::iterator i = it->begin(); i != it->end(); ++i)
            std::cout << ' ' << *i;
        std::cout << std::endl;
    }
}

void Map::takeTheL(void)
{
    _map[1][1] = ' ';
    _map[1][2] = ' ';
    _map[2][1] = ' ';
    _map[1][_width - 2] = ' ';
    _map[1][_width - 3] = ' ';
    _map[2][_width - 2] = ' ';
    _map[_height - 2][1] = ' ';
    _map[_height - 3][1] = ' ';
    _map[_height - 2][2] = ' ';
    _map[_height - 2][_width - 2] = ' ';
    _map[_height - 3][_width - 2] = ' ';
    _map[_height - 2][_width - 3] = ' ';
}

void Map::mapRand()
{
    int i = 0;
    std::random_device rd;

    for (int h = 1; h < _height; h++)
        for (int w = 1; w < _width; w++) {
            if (_map[h][w] == BLOCK) {
                i = rd() % 10;
                if (i == 0 || i == 1)
                    _map[h][w] = SPACE;
            }
        }
}

void Map::powerUp()
{
    int i = 0;
    int j = 0;
    std::random_device rd;

    for (int h = 1; h < _height; h++)
        for (int w = 1; w < _width; w++)
            if (_map[h][w] == BLOCK) {
                i = rd() % 30;  // Drop chance
                if (j == 5) { // If the guarantee drop rate is hit 
                    i = rd() % 5;
                    j = 0;
                }
                switch (i) {
                    case 0:
                        _map[h][w] = SLOWBOOTS;
                        j = 0;
                        break;
                    case 1:
                        _map[h][w] = FASTBOOTS ;
                        j = 0;
                        break;
                    case 2:
                        _map[h][w] = BIGBOMB;
                        j = 0;
                        break;
                    case 3:
                        _map[h][w] = SHIELD;
                        j = 0;
                        break;
                    case 4:
                        _map[h][w] = DOUBLEBOMB;
                        j = 0;
                        break;
                    default:
                        j++;
                }
                if (j == 5) // Make the current block drop a Power up
                    w--;
            }
}

const std::vector<std::vector<char>> &Map::getMap() const
{
    return _map;
}

int Map::getWidth() const
{
    return _width;
}

int Map::getHeight() const
{
    return _height;
}
