/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace) [WSL]
** File description:
** Window
*/

#include "irrlicht/Window.hpp"

using namespace irl;

Window::Window(const std::uint16_t width, const std::uint16_t height, std::wstring name) :
    _width(width),
    _height(height),
    _device(irr::createDevice(irr::video::EDT_SOFTWARE, dimension2d<u32>(width, height), 16,
            false, false, true, 0))
{
    if (_device == NULL) {
        std::cerr << "IndieEngine(): Failed to init IrrlichtDevice" << std::endl;
        exit(84);
    }
    _driver = _device->getVideoDriver();
    _smgr = _device->getSceneManager();
    _guienv = _device->getGUIEnvironment();
}

Window::~Window()
{
    _device->drop();
}

void Window::setFps(std::uint16_t fps)
{
}

bool Window::checkCloseEvent() const
{
    return _device->run();
}

void Window::beginDraw()
{
    _driver->beginScene(true, true, SColor(255,100,101,140));
}

void Window::endDraw()
{
    _smgr->drawAll();
    _guienv->drawAll();
    _driver->endScene();
}

const std::uint16_t &Window::getWidth() const
{
    return this->_width;
}

const std::uint16_t &Window::getHeight() const
{
    return this->_height;
}

IrrlichtDevice *Window::getDevice() const
{
    return _device;
}

IVideoDriver *Window::getVideoDriver() const
{
    return _driver;
}

ISceneManager &Window::getSceneManager() const
{
    return *_smgr;
}

IGUIEnvironment &Window::getGuiEnv() const
{
    return *_guienv;
}
