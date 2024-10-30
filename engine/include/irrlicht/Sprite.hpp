/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <vector>
#include "irrlicht/Texture.hpp"

namespace irl {
    class Sprite {
        public:
            Sprite();
            ~Sprite() = default;
            void appendTexture(Texture &texture);
            void displaySprite(float x, float y, std::uint32_t opacity);
            void setOpacity(std::uint32_t opacity) { _opacity = opacity; }
            [[nodiscard]] const std::uint32_t &getOpacity() const { return _opacity; }

        private:
            std::vector<Texture> _sprite;
            std::uint32_t _currentFrame;
            std::uint32_t _framesCounter;
            std::uint32_t _framesSpeed;
            std::uint32_t _opacity;
    };
}

#endif /* !SPRITE_HPP_ */
