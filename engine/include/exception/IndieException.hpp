/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** IndieException
*/

#ifndef INDIEEXCEPTION_HPP_
#define INDIEEXCEPTION_HPP_

#include <exception>
#include <string>

namespace indie
{
    class IndieException : public std::exception {
        public:
            IndieException(const std::string &what) : _what("IndieEngine(Exception): " + what) {}
            virtual ~IndieException() = default;

            const char *what() const noexcept {
                return _what.c_str();
            }
        private:
            std::string _what;
    };
}

#endif /* !INDIEEXCEPTION_HPP_ */