/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <string>

namespace ray {
    class Audio {
        public:
            Audio(std::string filepath);
            ~Audio();
            void playMusic();
            void updateMusic();
            void restartMusic();
            void pauseMusic();

        private:
            bool _pause;
    };
}

#endif /* !AUDIO_HPP_ */
