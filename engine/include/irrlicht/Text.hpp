/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>
#include <cstddef>
#include "irrlicht.h"

using namespace irr;
using namespace gui;
using namespace video;
using namespace core;

namespace irl {
    class Text {
        public:
            Text();
            ~Text();
            void renderText(rect<s32> &position);
            void setString(const stringw &str);
            void setFont(const std::string &path);
            void setColor(u32 r, u32 g, u32 b, u32 a);
            void setCenterV(bool center);
            void setCenterH(bool center);

        private:
            stringw _str;
            IGUIFont *_font;
            SColor _color;
            bool _hcenter;
            bool _vcenter;
    };
}

#endif /* !TEXT_HPP_ */