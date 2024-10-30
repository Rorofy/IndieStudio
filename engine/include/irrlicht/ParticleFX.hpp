/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** ParticleFX
*/

#ifndef PARTICLEFX_HPP_
#define PARTICLEFX_HPP_

#include "irrlicht.h"

namespace irl
{
    class ParticleFX {
        public:
            ParticleFX() : _system(NULL) {}
            ~ParticleFX() {
                if (_system != NULL) _system->remove();
            }

            void setSystem(irr::scene::IParticleSystemSceneNode *system) {
                _system = system;
            }

            irr::scene::IParticleSystemSceneNode *getSystem(void) {
                return _system;
            }

            void clean(void) {
                _system = NULL;
            }

            ParticleFX &operator=(ParticleFX &fx) {
                if (_system != NULL) _system->remove();
                _system = fx.getSystem();
                fx.clean();
                return *this;
            }

        private:
            irr::scene::IParticleSystemSceneNode *_system;
    };
}

#endif /* !PARTICLEFX_HPP_ */