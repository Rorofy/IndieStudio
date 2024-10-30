/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <iostream>
#include <unordered_map>
#include <memory>
#include "irrlicht.h"

namespace game
{
    class Settings {
        public:
            Settings() : _soundVolume(1), _framerate(60), _cheatMode(false) {
                setKey("up1", 'z');
                setKey("left1", 'q');
                setKey("right1", 'd');
                setKey("down1", 's');
                setKey("bomb1", 'e');
                setKey("up2", 'i');
                setKey("left2", 'j');
                setKey("right2", 'l');
                setKey("down2", 'k');
                setKey("bomb2", 'o');
                setKey("pause", 'p');
            }
            ~Settings() = default;

            void setSoundVolume(std::uint8_t volume) { _soundVolume = volume; }
            void setFramerate(std::uint8_t framerate) { _framerate = framerate; }
            void setCheatMode(bool mode) { _cheatMode = mode; }
            void setKey(const std::string &name, wchar_t key) {
                _keybinds[name] = key;
                _keybindsKeys[key] = name;
            }

            [[nodiscard]] const std::uint8_t getSoundVolume() const { return _soundVolume; }
            [[nodiscard]] const std::uint8_t getFramerate() const { return _framerate; }
            [[nodiscard]] const bool getCheatMode() const { return _cheatMode; }
            [[nodiscard]] const wchar_t getKey(const std::string &name) const { return _keybinds.at(name); }
            [[nodiscard]] const std::string &getKeyName(wchar_t key) { return _keybindsKeys[key]; }

        private:
            std::uint8_t _soundVolume;
            std::uint8_t _framerate;
            bool _cheatMode;
            std::unordered_map<std::string, wchar_t> _keybinds;
            std::unordered_map<wchar_t, std::string> _keybindsKeys;
    };

    extern std::unique_ptr<Settings> g_settings;
}

#endif /* !SETTINGS_HPP_ */
