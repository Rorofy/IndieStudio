/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-mihailo.pavlovic
** File description:
** RigidBody
*/

#ifndef RIGIDBODY_HPP_
#define RIGIDBODY_HPP_

#include "irrlicht/Object3d.hpp"

namespace irl
{
    class RigidBody 
    {
        public:
            void init(irl::Object3d &model);
            void setSize(int x, int y, int z);
            [[nodiscard]] const int &getX(void) const;
            [[nodiscard]] const int &getY(void) const;
            [[nodiscard]] const int &getZ(void) const;
            [[nodiscard]] irr::scene::ITriangleSelector *getSelector(void);
        private:
            int _x;
            int _y;
            int _z;
            irr::scene::ITriangleSelector *_selector;
    };
}
#endif /* !RIGIDBODY_HPP_ */
