/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL]
** File description:
** Window
*/

#include "raylib/Window.hpp"

using namespace ray;

Window::Window(const std::uint16_t width, const std::uint16_t height, std::string name) :
_width(width), _height(height)
{
    InitWindow(width, height, name.c_str());
    SetTargetFPS(60);
}

Window::~Window()
{
    CloseWindow();
}

void Window::setFps(std::uint16_t fps)
{
    SetTargetFPS(fps);
}

bool Window::checkCloseEvent() const
{
    return WindowShouldClose();
}

void Window::beginDraw()
{
    BeginDrawing();
    ClearBackground(BLUE);
}

void Window::endDraw()
{
    EndDrawing();
}

const std::uint16_t &Window::getWidth() const
{
    return this->_width;
}

const std::uint16_t &Window::getHeight() const
{
    return this->_height;
}
