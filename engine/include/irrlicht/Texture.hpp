/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <irrlicht.h>
#include <string>
#include <iostream>

using namespace irr;

namespace irl {
    class Texture {
        public:
            explicit Texture(const std::string &path, int offsetX, int offsetY, int width, int height);
            ~Texture();
            [[nodiscard]] const std::string &getPath() const;
            [[nodiscard]] const core::rect<s32> &getRect() const;
            [[nodiscard]] const video::ITexture *getTexture() const;

        private:
            std::string _path;
            core::rect<s32> _rect;
            video::ITexture *_texture;
    };
}

#endif /* !TEXTURE_HPP_ */
