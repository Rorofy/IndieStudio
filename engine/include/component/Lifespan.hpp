/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Lifespan
*/

#ifndef LIFESPAN_HPP_
#define LIFESPAN_HPP_

#include <functional>
#include "ecs/Scene.hpp"

namespace indie
{
    class Lifespan {
        public:
            Lifespan() = default;
            ~Lifespan() = default;

            void setLifespan(long lifespan) {
                _counter = lifespan;
            }

            long getLifespan(void) const {
                return _counter;
            }

            void setCallback(std::function<void (indie::Scene &, indie::Entity)> callback) {
                _haveCallback = true;
                _callback = callback;
            }

            const std::function<void (indie::Scene &, indie::Entity)> &getCallback(void) const {
                return _callback;
            }

            bool haveCallback(void) const {
                return _haveCallback;
            }

            void decrease(float amount) {
                _counter -= amount;
            };

        private:
            long _counter;
            bool _haveCallback;
            std::function<void (indie::Scene &, indie::Entity)> _callback;
    };
}

#endif /* !LIFESPAN_HPP_ */