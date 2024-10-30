/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** Destroyable
*/

#ifndef DESTROYABLE_HPP_
#define DESTROYABLE_HPP_

#include "ecs/Scene.hpp"

namespace game 
{
    class Destroyable 
    {
        public:
            class IDestroyCallback {
                public:
                    virtual ~IDestroyCallback() = default;

                    virtual bool destroy(indie::Scene &scene, indie::Entity) = 0;
            };
        public:
            Destroyable() = default;
            Destroyable(int value) : _value(value) {}
            ~Destroyable() = default;

            void setCallback(std::unique_ptr<IDestroyCallback> callback);
            const IDestroyCallback &getCallback(void) const;
            bool haveCallback(void) const;
            void destroy(indie::Scene &scene, indie::Entity entity) const;
        private:
            bool _value;
            std::shared_ptr<IDestroyCallback> _callback;

    };
}

#endif /* !DESTROYABLE_HPP_ */
