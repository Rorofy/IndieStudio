/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Audio
*/

#include "raylib/Audio.hpp"

using namespace ray;

Audio::Audio(std::string filepath) : _pause(false)
{
    InitAudioDevice();
    this->_music = LoadMusicStream(filepath.c_str());
}

Audio::~Audio()
{
    UnloadMusicStream(this->_music);
    CloseAudioDevice();
}

void Audio::playMusic()
{
    PlayMusicStream(this->_music);
}

void Audio::updateMusic()
{
    UpdateMusicStream(this->_music);
}

void Audio::restartMusic()
{
    StopMusicStream(this->_music);
    PlayMusicStream(this->_music);
}

void Audio::pauseMusic()
{
    this->_pause = !this->_pause;

    if (this->_pause)
        PauseMusicStream(this->_music);
    else
        ResumeMusicStream(this->_music);
}