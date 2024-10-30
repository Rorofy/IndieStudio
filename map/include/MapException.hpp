/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** MapException
*/

#ifndef MAPEXCEPTION_HPP_
#define MAPEXCEPTION_HPP_

#include <exception>
#include <string>

class MapException : public std::exception {
    public:
        MapException(std::string const &message, int const value) throw();
        ~MapException() throw();

        std::string getMapException() const;
        int getExitValue() const;

    private:
        std::string _errorMessage;
        int _exitValue;
};

#endif /* !MAPEXCEPTION_HPP_ */
