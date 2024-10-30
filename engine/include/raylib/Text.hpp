/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <raylib.h>

namespace ray {
    class Text {
        public:
            Text(std::string str, std::string fontPath, float posX,
                float posY, std::uint16_t fontSize, std::uint16_t spacing);
            ~Text();
            void displayText();
            void setString(const std::string str);
            void setFontSize(const std::uint16_t fontSize);
            void setSpacing(const std::uint16_t spaces);
            void setFont(const std::string fontPath);
            void setPos(const float x, const float y);
            void setColor(std::uint16_t r, std::uint16_t g, std::uint16_t b, std::uint16_t a);

        private:
            std::string _str;
            std::uint16_t _fontSize;
            std::uint16_t _spacing;
            Vector2 _pos;
            Font _font;
            Color _currentColor;
    };
}

#endif /* !TEXT_HPP_ */
