#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <irrlicht.h>
#include <iostream>
#include <string>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace irl {
    class Window
    {
        public:
            Window(const std::uint16_t width, const std::uint16_t height, std::wstring name);
            ~Window();

            void setFps(std::uint16_t fps);
            bool checkCloseEvent(void) const;
            void beginDraw(void);
            void endDraw(void);
            [[nodiscard]] const std::uint16_t &getWidth(void) const;
            [[nodiscard]] const std::uint16_t &getHeight(void) const;
            [[nodiscard]] IrrlichtDevice *getDevice(void) const;
            [[nodiscard]] IVideoDriver *getVideoDriver(void) const;
            [[nodiscard]] ISceneManager &getSceneManager(void) const;
            [[nodiscard]] IGUIEnvironment &getGuiEnv(void) const;

        private:
            IrrlichtDevice *_device;
            IVideoDriver *_driver;
            ISceneManager *_smgr;
            IGUIEnvironment *_guienv;

            const std::uint16_t _width;
            const std::uint16_t _height;
    };
}

#endif // !WINDOW_HPP